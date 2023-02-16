#include "Title.h"
#include "Play.h"
#include "../Stage/Background.h"
#include"../Pad/Pad.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
Title::Title()
    : SceneBase()
    , fadein(0)
    , bgPos(VGet(0, -1300, 0))
    , bgScrollSpeed(100.0f)
{
    // �^�C�g���摜�̓ǂݍ���
    sceneImage = LoadGraph("../asset/scene/title.png");
    bg = new Background();
    GamePad::SetPadUse(true);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Title::~Title()
{
    // �^�C�g���V�[���摜�̌�n��
    DeleteGraph(sceneImage);
    sceneImage = -1;
    delete bg;
}

/// <summary>
/// �^�C�g���V�[���̍X�V����
/// </summary>
/// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
/// <returns>���݂̃V�[���̃|�C���^</returns>
SceneBase* Title::Update(float _deltaTime)
{
    // �Q�[���p�b�h�̍X�V
    GamePad::Update();
    // �s�����łȂ����
    if (fadein <= 255)
    {
        // ���X�ɓ����ɂ��Ă���
        fadein++;
    }
    else
    {
        bgPos.x += bgScrollSpeed * _deltaTime;
        bgPos.y = 1300;

        // �G���^�[�������ꂽ��
        if (CheckHitKey(KEY_INPUT_RETURN)|| GamePad::GetButtonState(Button::START))
        {
            // �v���C�V�[���𐶐����ă|�C���^��Ԃ�
            return new Play();
        }
    }

    // �^�C�g���V�[���̃|�C���^��Ԃ�
    return this;
}

/// <summary>
/// �^�C�g���V�[���̕`�揈��
/// </summary>
void Title::Draw()
{
    // �w�i�X�N���[���`��
    bg->Draw((int)bgPos.x, (int)bgPos.y);

    // �t�F�[�h�C��
    SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, fadein);

    // �摜�`��
    DrawRotaGraph(960, 400, 1.5, 0, sceneImage, 1, 0);

    // �ȍ~�̉摜���[�h��W���ɐݒ�
    SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, fadein);
}
