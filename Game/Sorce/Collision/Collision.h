#pragma once

#include "DxLib.h"

//�����蔻��̕�
const int BOX_WIDTH = 40;

//�����蔻��̍���
const int BOX_HEIGHT = 40;

//�����蔻��̉��̐�
const int BOX_NUM_X = 162;

//�����蔻��̏c�̐�
const int BOX_NUM_Y = 54;

class Collision
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Collision();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Collision();

    /// <summary>
    /// �����蔻��
    /// </summary>
    bool CollBox(VECTOR& objPos);

private:

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
};