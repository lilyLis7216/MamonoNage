#pragma once

#include "DxLib.h"

/// <summary>
/// �X�N���[���N���X
/// </summary>
class Scroll
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Scroll();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Scroll();

    /// <summary>
    /// �X�N���[���̍X�V����
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    /// <param name="plyPos">�v���C���[�̍��W</param>
    void Update(float _deltaTime, VECTOR& plyPos);

    /// <summary>
    /// �X�N���[���̕`��I�t�Z�b�gX���擾
    /// </summary>
    /// <returns>X�����I�t�Z�b�g</returns>
    int GetDrawOffSetX();

    /// <summary>
    /// �X�N���[���̕`��I�t�Z�b�gY���擾
    /// </summary>
    /// <returns>Y�����I�t�Z�b�g</returns>
    int GetDrawOffSetY();

private:
    //�X�N���[��X
    float scrollX;

    //�X�N���[��Y
    float scrollY;

    //�E�����փX�N���[���J�n�ő���W
    const float scrMaxW = 1920 / 40 * 20;

    //�������փX�N���[���J�n�ő���W
    const float scrMaxH = 1080 / 40 * 25;

    //�������փX�N���[���J�n�ŏ����W
    const float scrMinW = 1920 / 40 * 15;

    //������փX�N���[���J�n�ŏ����W
    const float scrMinH = 1080 / 40 * 15;

    //X�����X�N���[���ő�l
    float scrMaxX;

    //Y�����X�N���[���ő�l
    float scrMaxY;

    //X�����X�N���[���ŏ��l
    float scrMinX;

    //Y�����X�N���[���ŏ��l
    float scrMinY;

    //�����߂����W
    float dx, dy; 
};