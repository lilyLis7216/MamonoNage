#pragma once

#include "SceneBase.h"
#include "DxLib.h"

/// <summary>
/// �^�C�g���V�[���iSceneBase���p���j
/// </summary>
class Title : public SceneBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Title();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Title();

    /// <summary>
    /// �^�C�g���V�[���̍X�V����
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    /// <returns>���݂̃V�[���̃|�C���^</returns>
    SceneBase* Update(float _deltaTime) override;

    /// <summary>
    /// �^�C�g���V�[���̕`�揈��
    /// </summary>
    void Draw() override;

private:
    // �����x
    int fadein;

    // �w�i���W
    VECTOR bgPos;

    // �w�i
    class Background* bg;

    // �w�i�X�N���[�����x
    float bgScrollSpeed;

    // �s�����x�ő�l
    const int maxFadein = 255;

    // �t�F�[�h���x
    const int fadeSpeed = 5;

};