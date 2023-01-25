#pragma once

#include <vector>
#include <unordered_map>

#include "../GameObject/GameObj.h"

using namespace std;

class GameObjMgr final
{
public:
    /// <summary>
    /// �C���X�^���X�̐���
    /// </summary>
    static void CreateInstance();

    /// <summary>
    /// �C���X�^���X�̍폜
    /// </summary>
    static void DeleteInstance();

    /// <summary>
    /// �Q�[���I�u�W�F�N�g�o�^
    /// </summary>
    /// <param name="newObj">�o�^����I�u�W�F�N�g�̃|�C���^</param>
    static void Entry(GameObj* newObj);

    /// <summary>
    /// �Q�[���I�u�W�F�N�g�폜
    /// </summary>
    /// <param name="releaseObj">�폜����I�u�W�F�N�g�̃|�C���^</param>
    static void Release(GameObj* relObj);

    /// <summary>
    /// �Q�[���I�u�W�F�N�g�S�폜
    /// </summary>
    static void ReleaseAllObj();

    /// <summary>
    /// �S�I�u�W�F�N�g�̍X�V����
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    static void Update(float _deltaTime);

    /// <summary>
    /// �S�I�u�W�F�N�g�̕`�揈��
    /// </summary>
    /// <param name="offSetX"></param>
    /// <param name="offSetY"></param>
    static void Draw(int offSetX, int offSetY);

    /// <summary>
    /// �I�u�W�F�N�g�^�O��̍ŏ���GameObj��Ԃ�
    /// </summary>
    /// <param name="tag">�^�O</param>
    /// <returns>�I�u�W�F�N�g�̃|�C���^</returns>
    static GameObj* GetFirstGameObj(ObjTag tag);


    static void Collision();
private:
    /// <summary>
    /// �R���X�g���N�^�i�V���O���g���j
    /// </summary>
    GameObjMgr();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~GameObjMgr();

    // �}�l�[�W���̃C���X�^���X�i�A�v�����ɗB�ꑶ�݁j
    static GameObjMgr* instance;

    // �ꎞ�ҋ@�I�u�W�F�N�g
    vector<GameObj*> pendingObjects;

    // objects[�^�O�i��ށj][�I�u�W�F�N�g��]
    unordered_map<ObjTag, vector<GameObj*>> objects;
};