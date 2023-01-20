#include "Result.h"
#include "DxLib.h"

Result::Result()
    : SceneBase()
{
    // ���U���g�V�[���摜�̓ǂݍ���
    sceneImage = LoadGraph("asset/scene/result.png");
}

Result::~Result()
{
    // ���U���g�V�[���摜�̌�n��
    DeleteGraph(sceneImage);
    sceneImage = -1;
}

/// <summary>
/// ���U���g�V�[���̍X�V����
/// </summary>
/// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
/// <returns>���݂̃V�[���̃|�C���^</returns>
SceneBase* Result::Update(float _deltaTime)
{
    // ���U���g�V�[���̃|�C���^��Ԃ�
    return nullptr;
}

/// <summary>
/// ���U���g�V�[���̕`�揈��
/// </summary>
void Result::Draw()
{
    DrawGraph(0, 0, sceneImage, true);
}
