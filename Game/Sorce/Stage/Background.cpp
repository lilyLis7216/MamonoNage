#include "Background.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Background::Background()
    : pos(VGet(0,0,0))
    , drawX(0)
    , drawY(0)
{
    // �w�ʃ��C���[�ǂݍ���
    back = LoadGraph("../asset/background/R2_distantView.png");

    // �������C���[�ǂݍ���
    mid = LoadGraph("../asset/background/R2_middleView.png");

    // �O�ʃ��C���[�ǂݍ���
    front = LoadGraph("../asset/background/R2_foreGround.png");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Background::~Background()
{
    DeleteGraph(back);
    DeleteGraph(mid);
    DeleteGraph(front);
}

/// <summary>
/// �w�i�̕`�揈��
/// </summary>
/// <param name="scrX"></param>
/// <param name="scrY"></param>
void Background::Draw(int scrX, int scrY)
{
    //----�X�N���[�����W���f----//
    drawX = (int)pos.x - scrX;
    drawY = (int)pos.y - scrY;

    //----�w�ʃ��C���[----//
    DrawGraph(drawX % ScreenW, drawY, back, TRUE);
    DrawGraph(drawX % ScreenW + ScreenW, drawY, back, TRUE);

    //----�������C���[----//
    DrawGraph(drawX * 2 % ScreenW, drawY, mid, TRUE);
    DrawGraph(drawX * 2 % ScreenW + ScreenW, drawY, mid, TRUE);

    //----�O�ʃ��C���[----//
    DrawGraph(drawX * 3 % ScreenW, drawY, front, TRUE);
    DrawGraph(drawX * 3 % ScreenW + ScreenW, drawY, front, TRUE);
}
