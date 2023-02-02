#include "Play.h"
#include "../Stage/Background.h"
#include "../Stage/Map.h"
#include "../Stage/Scroll.h"
#include "../Collision/MapCollision.h"
#include "../GameObject/Player/Player.h"
#include "../GameObject/Player/Bullet.h"
#include "../GameObject/Player/BulletDummy.h"
#include "../GameObject/Enemy/Slime.h"
#include "../Manager/BulletMgr.h"
#include "../Manager/GameObjMgr.h"
#include "../Manager/KeyMgr.h"
#include "../Scene/Result.h"


/// <summary>
/// コンストラクタ
/// </summary>
Play::Play()
    : SceneBase()
    , dummy()
    , bullet()
{
    GameObjMgr::CreateInstance();

    //---ステージ関連インスタンス---//
    bg = new Background();
    map = new Map();
    scroll = new Scroll();
    //block = new SkeltonBlock;

    //---当たり判定関連インスタンス---//
    MapCollision::CreateInstance();
    
    //---プレイヤー関連インスタンス---//
    player = new Player();
    bulletMgr = new BulletMgr();
    player->Init();
    GameObjMgr::Entry(player);

    //---エネミー関連インスタンス--//
    GameObjMgr::Entry(new Slime(VGet(50, 50, 0)));
    GameObjMgr::Entry(new Slime(VGet(500, 500, 0)));

}

/// <summary>
/// デストラクタ
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
/// プレイシーンの更新処理
/// </summary>
/// <param name="_deltaTime">1フレームの経過時間</param>
/// <returns>現在のシーンのポインタ</returns>
SceneBase* Play::Update(float _deltaTime)
{
    //isStand();
    ShotFlow(_deltaTime);

    GameObjMgr::Update(_deltaTime);
    scroll->Update(_deltaTime, player->GetPosition());

    // シーン遷移条件(スペースキーを押すと遷移（仮）)
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        MapCollision::DeleteInstance();
        GameObjMgr::DeleteInstance();
        // 条件を満たしていたらリザルトシーンを生成してそのポインタを返す
        return new Result();
    }

    // シーン遷移条件を満たしていなかったら今のポインタを返す
    return this;
}

/// <summary>
/// プレイシーンの描画処理
/// </summary>
void Play::Draw()
{
    bg->Draw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());
    map->Draw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());
    //block->Draw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());

    GameObjMgr::Draw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());
    unsigned int Color;

    Color = GetColor(255, 255, 255);
    DrawFormatString(0, 0, Color, "残弾 i の値は %d です", bulletMgr->GetBulletNum());
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
    if (KeyMgr::KeyStatusI() == 3) {
        bulletMgr->AddBulletNum();
    }

    if (bulletMgr->GetBulletNum() > 0)
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
            bulletMgr->SubBulletNum();
            player->SetThrowAnimationFlag(TRUE);
            dummy->SetAlive(false);
        }
        else
        {
        }
    }
}
