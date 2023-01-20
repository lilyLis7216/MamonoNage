#pragma once

// �}�b�v�Z���̉���
const int CELL_WIDTH = 40;

// �}�b�v�Z���̍���
const int CELL_HEIGHT = 40;

// x�����̃^�C����
const int CELL_NUM_X = 162;

// y�����̃^�C����
const int CELL_NUM_Y = 54;

/// <summary>
/// �}�b�v�N���X
/// </summary>
class Map final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Map();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Map();

    /// <summary>
    /// �}�b�v�̕`��
    /// </summary>
    /// <param name="scrX"></param>
    /// <param name="scrY"></param>
    void Draw(int scrX, int scrY);

protected:

    struct mapLayer
    {
        int graphicHandle;
    };

    // 
    mapLayer map[CELL_NUM_X][CELL_NUM_Y] = { 0 };

    // 
    int chipGraphicHandle[(200 / 40) * (40 / 40)];

    // 
    int characterPack;

    // �������^�C���i���o�[
    int rawNum = 0;

    // �c�����^�C���i���o�[
    int columnNum = 0;

    // �^�C���̔ԍ�
    int num = 0;

    // ������ϐ�
    char buf[10];

    // eof���o�t���O
    bool eofFlag = false;
};