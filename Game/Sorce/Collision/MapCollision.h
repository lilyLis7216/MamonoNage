#pragma once
#include "DxLib.h"
#include"../GameObject/GameObj.h"

//�����蔻��̕�
const int BOX_WIDTH = 40;

//�����蔻��̍���
const int BOX_HEIGHT = 40;

//�����蔻��̉��̐�
const int BOX_NUM_X = 150;

//�����蔻��̏c�̐�
const int BOX_NUM_Y = 54;

class MapCollision
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


    bool HitBlockType(int num, int num2, int blockType);

    static MapCollision* GetMapCol() { return mapcol; }
private:
    MapCollision();
    ~MapCollision();

    struct collLayer
    {
        int boxHandle;
    };

    collLayer coll[BOX_NUM_X][BOX_NUM_Y];

    // �����蔻��̎��
    int collBoxHandle[5];

    // �������i�[����ϐ�
    int marker;

    // �������̃^�C���i���o�[
    int rawNum;

    // �c�����̃^�C���i���o�[
    int columnNum;

    // �����蔻��̔ԍ�
    int num;

    // ������ϐ�
    char buf[10];

    // eof���o�t���O
    bool eofFlag;

    static MapCollision* mapcol;
};

