#include "Result.h"
#include "DxLib.h"
#include "../Scene/Title.h"

Result::Result(bool clearflag)
    : SceneBase()
{
    // ���U���g�V�[���摜�̓ǂݍ���
    if (clearflag)
    {
        sceneImage = LoadGraph("../asset/scene/_clearbg.png");
        gameclearImg = LoadGraph("../asset/scene/gameclear.png");
    }
    if (!clearflag)
    {
        sceneImage = LoadGraph("../asset/scene/gameoverbg.jpg");
        gameoverImg = LoadGraph("../asset/scene/gameover.png");
        continueImg = LoadGraph("../asset/scene/continue.png");
    }
}

Result::~Result()
{
    // ���U���g�V�[���摜�̌�n��
    DeleteGraph(sceneImage);
    sceneImage = -1;
    gameoverImg = -1;
    continueImg = -1;
}

/// <summary>
/// ���U���g�V�[���̍X�V����
/// </summary>
/// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
/// <returns>���݂̃V�[���̃|�C���^</returns>
SceneBase* Result::Update(float _deltaTime)
{
    // �V�[���J�ڏ���(�X�y�[�X�L�[�������ƑJ�ځi���j)
    if (CheckHitKey(KEY_INPUT_A))
    {
        // �����𖞂����Ă����烊�U���g�V�[���𐶐����Ă��̃|�C���^��Ԃ�
        return new Title();
    }
    // ���U���g�V�[���̃|�C���^��Ԃ�
    return this;
}

/// <summary>
/// ���U���g�V�[���̕`�揈��
/// </summary>
void Result::Draw()
{
    DrawGraph(0, 0, sceneImage, true);
    DrawGraph(100, 200, gameoverImg, true);
    DrawGraph(300, 350, gameclearImg, true);
    DrawRotaGraph(900, 700,0.8f,0, continueImg, true);
}
