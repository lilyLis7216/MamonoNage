#pragma once

#include "SceneBase.h"

class Result : public SceneBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Result(bool clearflag);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Result();

    /// <summary>
    /// ���U���g�V�[���̍X�V����
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    /// <returns>���݂̃V�[���̃|�C���^</returns>
    SceneBase* Update(float _deltaTime) override;

    /// <summary>
    /// ���U���g�V�[���̕`�揈��
    /// </summary>
    void Draw() override;
private:
    int gameoverImg = -1;
    int continueImg = -1;
    int gameclearImg = -1;
};