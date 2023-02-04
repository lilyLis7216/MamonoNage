#include "Play.h"
#include "../Stage/Background.h"
#include "../Stage/Map.h"
#include "../Stage/Scroll.h"
#include "../Collision/MapCollision.h"
#include "../GameObject/Player/Player.h"
#include "../GameObject/Player/Bullet.h"
#include "../GameObject/Player/BulletDummy.h"
#include "../GameObject/Enemy/Slime.h"
#include "../GameObject/Enemy/Bat.h"
#include "../GameObject/Enemy/Skeleton.h"
#include "../Manager/BulletMgr.h"
#include "../Manager/GameObjMgr.h"
#include "../Manager/KeyMgr.h"
#include "../Scene/Result.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
Play::Play()
    : SceneBase()
    , dummy()
    , bullet()
{
    GameObjMgr::CreateInstance();

    //---�X�e�[�W�֘A�C���X�^���X---//
    bg = new Background();
    map = new Map();
    scroll = new Scroll();
    //block = new SkeltonBlock;

    //---�����蔻��֘A�C���X�^���X---//
    MapCollision::CreateInstance();
    
    //---�v���C���[�֘A�C���X�^���X---//
    player = new Player();
    bulletMgr = new BulletMgr();
    player->Init();
    GameObjMgr::Entry(player);

    //---�G�l�~�[�֘A�C���X�^���X--//
    GameObjMgr::Entry(new Bat(VGet(50, 100, 0)));
    GameObjMgr::Entry(new Skeleton(VGet(120,105, 0)));

    GameObjMgr::Entry(new Bat(VGet(1960, 700, 0)));//�R�E����1�̏����ʒu���W
    GameObjMgr::Entry(new Bat(VGet(2600, 700, 0)));//�R�E����2�̏����ʒu���W
    GameObjMgr::Entry(new Bat(VGet(2600, 1400, 0)));//�R�E����3�̏����ʒu���W
    GameObjMgr::Entry(new Bat(VGet(4600, 1250, 0)));//�R�E����4�̏����ʒu���W
    GameObjMgr::Entry(new Bat(VGet(4900, 1150, 0)));//�R�E����5�̏����ʒu���W


    GameObjMgr::Entry(new Skeleton(VGet(2300, 2000, 0)));//�X�P���g��1�̏����ʒu���W
    GameObjMgr::Entry(new Skeleton(VGet(2450, 2000, 0)));//�X�P���g��2�̏����ʒu���W
    GameObjMgr::Entry(new Skeleton(VGet(2600, 2000, 0)));//�X�P���g��3�̏����ʒu���W
    GameObjMgr::Entry(new Skeleton(VGet(3920, 1450, 0)));//�X�P���g��4�̏����ʒu���W
    GameObjMgr::Entry(new Skeleton(VGet(5800, 450, 0)));//�X�P���g��5�̏����ʒu���W
    GameObjMgr::Entry(new Skeleton(VGet(6300, 450, 0)));//�X�P���g��6�̏����ʒu���W
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Play::~Play()
{
    delete bg;
    delete map;
    delete scroll;
    delete player;
    delete bulletMgr;
}

/// <summary>
/// �v���C�V�[���̍X�V����
/// </summary>
/// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
/// <returns>���݂̃V�[���̃|�C���^</returns>
SceneBase* Play::Update(float _deltaTime)
{
    //isStand();
    ShotFlow(_deltaTime);

    GameObjMgr::Update(_deltaTime);
    scroll->Update(_deltaTime, player->GetPosition());

    // �V�[���J�ڏ���(�X�y�[�X�L�[�������ƑJ�ځi���j)
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        MapCollision::DeleteInstance();
        GameObjMgr::DeleteInstance();
        // �����𖞂����Ă����烊�U���g�V�[���𐶐����Ă��̃|�C���^��Ԃ�
        return new Result();
    }

    // �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
    return this;
}

/// <summary>
/// �v���C�V�[���̕`�揈��
/// </summary>
void Play::Draw()
{
    bg->Draw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());
    map->Draw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());
    //block->Draw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());

    GameObjMgr::Draw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());
    unsigned int Color;

    Color = GetColor(255, 255, 255);
    DrawFormatString(0, 0, Color, "�c�e i �̒l�� %d �ł�", bulletMgr->GetBulletNum(BulletMgr::current_type));
}

//void Play::isStand()
//{
//    player->SetonGround(collision->CollBox(player->GetPosition()));
//    //block->CheckPlayerHit(player);
//    if (bullet != nullptr)
//    {
//        bullet->SetonGround(collision->CollBox(bullet->GetPosition()));
//        //block->CheckBulletHit(bullet);
//    }
//}

void Play::ShotFlow(float _deltaTime)
{   
    BulletMgr::AddGoastBulletNum(_deltaTime);

    //I�{�^���Œe��؂�ւ���
    if (KeyMgr::KeyStatusI() == 3) {
        BulletMgr::SwitchType(BulletMgr::current_type);
    }

    if (bulletMgr->GetBulletNum(BulletMgr::current_type) > 0)
    {
        int tmp = KeyMgr::KeyStatusP();
        if (tmp == 1) {
            dummy = new BulletDummy(player);
            GameObjMgr::Entry(dummy);
        }

        else if (tmp == 2) {
            dummy->AddRadian(_deltaTime);
            dummy->SetPos(player->GetPos());
        }

        else if (tmp == 3)
        {
            bullet = new Bullet(player);
            GameObjMgr::Entry(bullet);
            bullet->SetBulletDir(dummy->GetBulletDummyDir());
            bullet->BulletAngleSet(dummy->GetRadian());
            bulletMgr->SubBulletNum(BulletMgr::current_type);
            player->SetThrowAnimationFlag(TRUE);
            dummy->SetAlive(false);
        }
        else
        {
        }
    }
}
