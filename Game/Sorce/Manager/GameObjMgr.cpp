#include "GameObjMgr.h"
#include"../Collision/MapCollision.h"

// GameObjMgr実体へのポインタ定義
GameObjMgr* GameObjMgr::instance = nullptr;

GameObjMgr::GameObjMgr()
    : objects()
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
    // 一時待機オブジェクト内から検索
    auto iter = find(instance->pendingObjects.begin(), instance->pendingObjects.end(), relObj);
    if (iter != instance->pendingObjects.end())
    {
        // 見つけたオブジェクトを最末尾に移動して削除
        iter_swap(iter, instance->pendingObjects.end() - 1);
        instance->pendingObjects.pop_back();

        return;
    }

    // 解放オブジェクトのタグ種類を得る
    ObjTag tag = relObj->GetTag();

    // 実行オブジェクト内から検索
    iter = find(instance->objects[tag].begin(), instance->objects[tag].end(), relObj);
    if (iter != instance->objects[tag].end())
    {
        // 見つけたオブジェクトを末尾に移動して削除
        iter_swap(iter, instance->objects[tag].end() - 1);
        delete instance->objects[tag].back();
    }
}

void GameObjMgr::ReleaseAllObj()
{
    // 末尾から一時待機オブジェクトを全て削除
    while (!instance->pendingObjects.empty())
    {
        delete instance->pendingObjects.back();
    }

    // 全ての実行オブジェクトを
    for (auto& tag : ObjTagAll)
    {
        // 末尾から削除
        while (!instance->objects[tag].empty())
        {
            delete instance->objects[tag].back();
            instance->objects[tag].pop_back();
        }
    }
}

void GameObjMgr::Update(float _deltaTime)
{
    // 全オブジェクトの更新
    for (auto& tag : ObjTagAll)
    {
        // 該当タグにある全ての実行オブジェクトを更新
        for (int i = 0; i < instance->objects[tag].size(); ++i)
        {
            instance->objects[tag][i]->Update(_deltaTime);
        }
    }

    // 一時待機中のオブジェクトを実行リストに追加
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

        instance->objects[tag].erase(remove_if(begin(instance->objects[tag]), 
            end(instance->objects[tag]), [](GameObj* g) {return !g->GetAlive(); }), cend(instance->objects[tag]));
    }

    // 死んでいるGameObjをここで完全削除
    while (!deadObjects.empty())
    {
        delete deadObjects.back();
        deadObjects.pop_back();
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

void GameObjMgr::Collision()
{
    for (int plynum = 0; plynum < instance->objects[ObjTag::Player].size(); ++plynum)
    {
        instance->objects[ObjTag::Player][plynum]->MapColEnter();
    }
}

GameObj* GameObjMgr::GetFirstGameObj(ObjTag tag)
{
    if (instance->objects[tag].size() == 0)
    {
        return nullptr;
    }
    return instance->objects[tag][0];
}
