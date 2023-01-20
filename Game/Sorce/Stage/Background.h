#pragma once

#include "DxLib.h"

// ��ʉ���
const int ScreenW = 1920;

// ��ʏc��
const int ScreenH = 1080;

/// <summary>
/// �w�i�N���X
/// </summary>
class Background
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Background();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Background();

    /// <summary>
    /// �w�i�̕`�揈��
    /// </summary>
    /// <param name="scrX"></param>
    /// <param name="scrY"></param>
    void Draw(int scrX, int scrY);

private:
    // �w�ʃ��C���[
    int back;

    // �������C���[
    int mid;

    // �O�ʃ��C���[
    int front;

    // �`����Wx
    int drawX;

    // �`����Wy
    int drawY;

    // �w�i���W
    VECTOR pos;
};