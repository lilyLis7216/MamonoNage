#include "Scroll.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Scroll::Scroll()
    : scrollX(0)
    , scrollY(0)
    , dx(0)
    , dy(0)
{
    scrMaxX = 40 * 162 - 1920;
    scrMaxY = 40 * 58 - 1080;
    scrMinX = 0;
    scrMinY = 0;
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Scroll::~Scroll()
{
}

/// <summary>
/// �X�N���[���̍X�V����
/// </summary>
/// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
/// <param name="plyPos">�v���C���[�̍��W</param>
void Scroll::Update(float _deltaTime, VECTOR& plyPos)
{
    dx = dy = 0;

    //---�v���C���[�����߂�����---//
    //�E�ɃX�N���[��������W�𒴂�����
    if (plyPos.x + 64 > scrollX + scrMaxW)
    {
        //���ɉ����߂�
        dx = plyPos.x + 64 - (scrollX + scrMaxW);
    }

    //���X�N���[��
    if (plyPos.y + 64 > scrollY + scrMaxH)
    {
        dy = plyPos.y + 64 - (scrollY + scrMaxH);
    }

    //���X�N���[��
    if (plyPos.x - 64 < scrollX + scrMinW)
    {
        dx = plyPos.x - 64 - (scrollX + scrMinW);
    }

    //��X�N���[��
    if (plyPos.y - 64 < scrollY + scrMinH)
    {
        dy = plyPos.y - 64 - (scrollY + scrMinH);
    }

    //�����߂�X
    scrollX += dx;

    //�����߂�Y
    scrollY += dy;

    //---�X�N���[�����W�ő�l����---//
    //�E�X�N���[�����W�ő�l�܂ł�����
    if (scrollX > scrMaxX)
    {
        //�X�N���[����~
        scrollX = scrMaxX;
    }
    //���X�N���[��
    else if (scrollX < scrMinX)
    {
        scrollX = scrMinX;
    }

    //���X�N���[��
    if (scrollY > scrMaxY)
    {
        scrollY = scrMaxY;
    }
    //��X�N���[��
    else if (scrollY < scrMinY)	
    {
        scrollY = scrMinY;
    }
}

/// <summary>
/// �X�N���[���̕`��I�t�Z�b�gX���擾
/// </summary>
/// <returns>X�����I�t�Z�b�g</returns>
int Scroll::GetDrawOffSetX()
{
    return static_cast<int>(scrollX);
}

/// <summary>
/// �X�N���[���̕`��I�t�Z�b�gY���擾
/// </summary>
/// <returns>Y�����I�t�Z�b�g</returns>
int Scroll::GetDrawOffSetY()
{
    return static_cast<int>(scrollY);
}
