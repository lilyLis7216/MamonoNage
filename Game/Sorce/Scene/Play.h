#pragma once

#include "SceneBase.h"

class Play : public SceneBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Play();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Play();

    /// <summary>
    /// �v���C�V�[���̍X�V����
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    /// <returns>���݂̃V�[���̃|�C���^</returns>
    SceneBase* Update(float _deltaTime) override;

    /// <summary>
    /// �v���C�V�[���̕`�揈��
    /// </summary>
    void Draw() override;
};