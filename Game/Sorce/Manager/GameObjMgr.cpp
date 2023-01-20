#include "GameObjMgr.h"

// GameObjMgr���̂ւ̃|�C���^��`
GameObjMgr* GameObjMgr::instance = nullptr;

GameObjMgr::GameObjMgr()
{
    instance = nullptr;
}

GameObjMgr::~GameObjMgr()
{
    ReleaseAllObj();
}

void GameObjMgr::CreateInstance()
{
    if (!instance)
    {
        instance = new GameObjMgr();
    }
}

void GameObjMgr::DeleteInstance()
{
    ReleaseAllObj();
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

void GameObjMgr::Entry(GameObj* newObj)
{
    instance->pendingObjects.push_back(newObj);
}

void GameObjMgr::Release(GameObj* relObj)
{
    // �ꎞ�ҋ@�I�u�W�F�N�g�����猟��
    auto iter = find(instance->pendingObjects.begin(), instance->pendingObjects.end(), relObj);
    if (iter != instance->pendingObjects.end())
    {
        // �������I�u�W�F�N�g���Ŗ����Ɉړ����č폜
        iter_swap(iter, instance->pendingObjects.end() - 1);
        instance->pendingObjects.pop_back();

        return;
    }

    // ����I�u�W�F�N�g�̃^�O��ނ𓾂�
    ObjTag tag = relObj->GetTag();

    // ���s�I�u�W�F�N�g�����猟��
    iter = find(instance->objects[tag].begin(), instance->objects[tag].end(), relObj);
    if (iter != instance->objects[tag].end())
    {
        // �������I�u�W�F�N�g�𖖔��Ɉړ����č폜
        iter_swap(iter, instance->objects[tag].end() - 1);
        delete instance->objects[tag].back();
    }
}

void GameObjMgr::ReleaseAllObj()
{
    // ��������ꎞ�ҋ@�I�u�W�F�N�g��S�č폜
    while (instance->pendingObjects.empty())
    {
        delete instance->pendingObjects.back();
    }

    // �S�Ă̎��s�I�u�W�F�N�g��
    for (auto& tag : ObjTagAll)
    {
        // ��������폜
        while (instance->objects[tag].empty())
        {
            delete instance->objects[tag].back();
            instance->objects[tag].pop_back();
        }
    }
}

void GameObjMgr::Update(float _deltaTime)
{
    // �S�I�u�W�F�N�g�̍X�V
    for (auto& tag : ObjTagAll)
    {
        // �Y���^�O�ɂ���S�Ă̎��s�I�u�W�F�N�g���X�V
        for (int i = 0; i < instance->objects[tag].size(); ++i)
        {
            instance->objects[tag][i]->Update(_deltaTime);
        }
    }

    // �ꎞ�ҋ@���̃I�u�W�F�N�g�����s���X�g�ɒǉ�
    for (auto pending : instance->pendingObjects)
    {
        ObjTag tag = pending->GetTag();
        instance->objects[tag].emplace_back(pending);
    }
    instance->pendingObjects.clear();

    vector<GameObj*> deadObjects;
    for (auto& tag : ObjTagAll)
    {
        for (auto obj : instance->objects[tag])
        {
            if (!obj->GetAlive())
            {
                deadObjects.emplace_back(obj);
            }
        }

        auto release = instance->objects[tag];
        release.erase(remove_if(begin(release), end(release), [](GameObj* g) {return !g->GetAlive(); }), cend(release));

        // ����ł���GameObj�������Ŋ��S�폜
        while (!deadObjects.empty())
        {
            delete deadObjects.back();
            deadObjects.pop_back();
        }
    }
}

void GameObjMgr::Draw(int offSetX, int offSetY)
{
    for (auto& tag : ObjTagAll)
    {
        for (int i = 0; i < instance->objects[tag].size(); ++i)
        {
            instance->objects[tag][i]->Draw(offSetX, offSetY);
        }
    }
}

GameObj* GameObjMgr::GetFirstGameObj(ObjTag tag)
{
    return nullptr;
}
