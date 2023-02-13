#pragma once

#include "SceneBase.h"

class Background;
class Map;
class Scroll;
class MapCollision;
//class SkeltonBlock;

class Player;
class BulletDummy;
class Bullet;
class BulletMgr;

class Play : public SceneBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Play();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Play();

    /// <summary>
    /// プレイシーンの更新処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    /// <returns>現在のシーンのポインタ</returns>
    SceneBase* Update(float _deltaTime) override;

    /// <summary>
    /// プレイシーンの描画処理
    /// </summary>
    void Draw() override;

    ///// <summary>
    ///// キャラが地面に立っているかどうか調べる
    ///// </summary>
    //void isStand();

    /// <summary>
    /// キャラがバレットを投げるまでの流れ
    /// </summary>
    void ShotFlow(float _deltaTime);

    /// <summary>
    /// バレットの出現
    /// </summary>
    void BulletRepop();
private:
    Background* bg;
    Map* map;
    Scroll* scroll;
    MapCollision* mapcol=nullptr;
    // SkeltonBlock* block;

    Player* player;
    BulletDummy* dummy;
    Bullet* bullet;
    BulletMgr* bulletMgr;
};