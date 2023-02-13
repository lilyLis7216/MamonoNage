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
#include "../Manager/EffectMgr.h"
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

    
    


    ////---エネミー関連インスタンス--//
    //GameObjMgr::Entry(new Bat(VGet(50, 100, 0)));
    //GameObjMgr::Entry(new Skeleton(VGet(120,105, 0)));

    GameObjMgr::Entry(new Bat(VGet(1960, 700, 0)));//コウモリ1の初期位置座標
    GameObjMgr::Entry(new Bat(VGet(2600, 700, 0)));//コウモリ2の初期位置座標
    GameObjMgr::Entry(new Bat(VGet(2600, 1400, 0)));//コウモリ3の初期位置座標
    GameObjMgr::Entry(new Bat(VGet(4600, 1250, 0)));//コウモリ4の初期位置座標
    GameObjMgr::Entry(new Bat(VGet(4900, 1150, 0)));//コウモリ5の初期位置座標


    GameObjMgr::Entry(new Skeleton(VGet(2300, 2000, 0)));//スケルトン1の初期位置座標
    GameObjMgr::Entry(new Skeleton(VGet(2450, 2000, 0)));//スケルトン2の初期位置座標
    GameObjMgr::Entry(new Skeleton(VGet(2600, 2000, 0)));//スケルトン3の初期位置座標
    GameObjMgr::Entry(new Skeleton(VGet(3920, 1450, 0)));//スケルトン4の初期位置座標
    GameObjMgr::Entry(new Skeleton(VGet(5800, 450, 0)));//スケルトン5の初期位置座標
    GameObjMgr::Entry(new Skeleton(VGet(6300, 450, 0)));//スケルトン6の初期位置座標
}

/// <summary>
/// デストラクタ
/// </summary>
Play::~Play()
{
    delete bg;
    delete map;
    delete scroll;
    //delete player;
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
    GameObjMgr::ObjCollision();
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
    BulletMgr::Draw(player->GetPos(), player->GetDir(), scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());

    unsigned int Color;

    Color = GetColor(255, 255, 255);
    DrawFormatString(0, 0, Color,"%d", bulletMgr->GetBulletNum(BulletMgr::current_type));
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
    BulletMgr::AutoSwitchType(BulletMgr::current_type);

    //Iボタンで弾を切り替える
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
            player->SetThrowPrepaAnimationFlag(TRUE);
        }

        else if (tmp == 3)
        {
            bullet = new Bullet(player);
            GameObjMgr::Entry(bullet);
            bullet->SetBulletDir(dummy->GetBulletDummyDir());
            bullet->BulletAngleSet(dummy->GetRadian());
            
            bulletMgr->SubBulletNum(BulletMgr::current_type);
            player->SetThrowPrepaAnimationFlag(FALSE);
            player->SetThrowAnimationFlag(TRUE);
            dummy->SetAlive(false);
        }
        else
        {
        }
    }
}

void Play::BulletRepop()
{

}
