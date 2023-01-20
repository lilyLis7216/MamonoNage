#pragma once

#include "DxLib.h"

//1�Ԗڂ̃u���b�N
const int FIRST_POSITION_X = 1440;
const int FIRST_POSITION_Y = 640;

//2�Ԗڂ̃u���b�N
const int SECOND_POSITION_X = 3040;
const int SECOND_POSITION_Y = 640;

//3�Ԗڂ̃u���b�N
const int THIRD_POSITION_X = 4120;
const int THIRD_POSITION_Y = 560;

//4�Ԗڂ̃u���b�N
const int FOURTH_POSITION_X = 4360;
const int FOURTH_POSITION_Y = 1280;

//5�Ԗڂ̃u���b�N
const int FIFTH_POSITION_X = 4680;
const int FIFTH_POSITION_Y = 1200;

//6�Ԗڂ̃u���b�N
const int SIXTH_POSITION_X = 5040;
const int SIXTH_POSITION_Y = 1160;

//�����蔻��̕�
const int BLOCK_WIDTH = 160;

//�����蔻��̍���
const int BLOCK_HEIGHT = 80;

/// <summary>
/// �X�P���g���u���b�N�N���X
/// </summary>
class SkeltonBlock
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    SkeltonBlock();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~SkeltonBlock();

    /// <summary>
    /// ��������̕`��
    /// </summary>
    /// <param name="scrX"></param>
    /// <param name="scrY"></param>
    void Draw(int scrX, int scrY);

    /// <summary>
    /// �����蔻��
    /// </summary>
    //����`�F�b�N
    void CheckPlayerHit(class Player* player);
    void CheckBulletHit(class Bullet* bullet);

    //�e�u���b�N����(�v���C���[�ƒe)
    //1�Ԗ�
    bool PlayerFirstColBox(VECTOR& objPos);
    bool BulletFirstColBox(VECTOR& objPos);

    //2�Ԗ�
    bool PlayerSecondColBox(VECTOR& objPos);
    bool BulletSecondColBox(VECTOR& objPos);

    //3�Ԗ�
    bool PlayerThirdColBox(VECTOR& objPos);
    bool BulletThirdColBox(VECTOR& objPos);

    //4�Ԗ�
    bool PlayerFourthColBox(VECTOR& objPos);
    bool BulletFourthColBox(VECTOR& objPos);

    //5�Ԗ�
    bool PlayerFifthColBox(VECTOR& objPos);
    bool BulletFifthColBox(VECTOR& objPos);

    //6�Ԗ�
    bool PlayerSixthColBox(VECTOR& objPos);
    bool BulletSixthColBox(VECTOR& objPos);

private:
    //1�Ԗڂ̃u���b�N
    int FirstFalseImg;
    int FirstTrueImg;
    int FirstX;
    int FirstY;
    bool FirstVisibleFlag = false;

    //2�Ԗڂ̃u���b�N
    int SecondFalseImg;
    int SecondTrueImg;
    int SecondX;
    int SecondY;
    bool SecondVisibleFlag = false;

    //3�Ԗڂ̃u���b�N
    int ThirdFalseImg;
    int ThirdTrueImg;
    int ThirdX;
    int ThirdY;
    bool ThirdVisibleFlag = false;

    //4�Ԗڂ̃u���b�N
    int FourthFalseImg;
    int FourthTrueImg;
    int FourthX;
    int FourthY;
    bool FourthVisibleFlag = false;

    //5�Ԗڂ̃u���b�N
    int FifthFalseImg;
    int FifthTrueImg;
    int FifthX;
    int FifthY;
    bool FifthVisibleFlag = false;

    //5�Ԗڂ̃u���b�N
    int SixthFalseImg;
    int SixthTrueImg;
    int SixthX;
    int SixthY;
    bool SixthVisibleFlag = false;

    // ��
    int width;

    // ����
    int height;

    // �X�N���[������
    int offSetX;
    int offSetY;
};