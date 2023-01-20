#pragma once

class SceneBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    SceneBase();

    /// <summary>
    /// ���z�f�X�g���N�^
    /// </summary>
    virtual ~SceneBase();

    /// <summary>
    /// �V�[���̍X�V����
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    /// <returns>���݂̃V�[���̃|�C���^</returns>
    virtual SceneBase* Update(float _deltaTime) = 0;

    /// <summary>
    /// �V�[���̕`�揈��
    /// </summary>
    virtual void Draw() = 0;

protected:
    // �V�[���̉摜
    int sceneImage;
};