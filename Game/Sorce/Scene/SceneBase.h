#pragma once

const int ScreenBeside = 1920;
const int ScreenVertical = 1080;
const int ColorDepth = 16;

/// <summary>
/// �V�[���x�[�X�N���X
/// </summary>
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