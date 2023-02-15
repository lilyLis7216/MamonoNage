#pragma once

#include "../GameObj.h"
#include "../Player/Bullet.h"
#include "../../Manager/EffectMgr.h"
#include "../../Manager/KeyMgr.h"
#include "../../Manager/BulletMgr.h"
#include "../../Manager/GameObjMgr.h"
//サイズ
const int EnemyXSize = 64;
const int EnemyYSize = 64;

//アニメーションの共通要素(被ダメージはXNumが２)
const int EnemyXNum = 4;
const int EnemyYNum = 1;


//移動アニメーション
const int EnemyMoveAllNum = 4;
//攻撃アニメーション関連
const int EnemyAttackAllNum = 4;
//被ダメージアニメーション
const int EnemyDamageAllNum = 2;
const int EnemyDamageXNum = 2;
/// <summary>
/// モンスタークラス（GameObj継承）
/// </summary>
class Monster : public GameObj
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Monster();

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="pos">初期座標</param>
    Monster(BulletMgr::BulletType bulletType,VECTOR pos);

    /// <summary>
    /// 仮想デストラクタ
    /// </summary>
    virtual ~Monster();

    //動き
    void Move(float _deltaTime);
    //方向転換
    void DirReverse(VECTOR ret);
    // 走りアニメーション設定
    void MoveAnimation(float _deltaTime);
    //被ダメージアニメーション設定
    void DamageAnimation(float _deltaTime);
    //攻撃アニメーション設定
    void AttackAnimation(float _deltaTime);
    //アニメーションコントロール
    void AnimationControl();
    
    //エネミータイプを取る
    int GetemyType() { return emyType; }
    
    //
    int GetHandle() { return handle; }
    


    //当たり判定
    void OnCollisionEnter(GameObj* other);
    void MapColEnter()override;

protected:
    BulletMgr::BulletType emyType;

    //座標関連
    
    VECTOR tmpPos = VGet(0,0,0);

    // 速度
    float speed=0.0f;

    //重力関連
    float mEmyVy;
    bool onEmyGround;
    bool onFirstEmyGround=false;

    //動きモーション
    int mMove[EnemyMoveAllNum] = { -1 };
    int mMoveAnimation = 0;
    float mMoveAnimCoolTime = 0.2f;
    

    //攻撃モーション
    int mAttack[EnemyAttackAllNum] = { -1 };
    int mAttackAnimation = 0;
    float mAttackAnimCoolTime = 0.2f;
    bool mAttackAnimationFlag = FALSE;

    //被ダメ―ジモーション
    int mDamage[EnemyDamageAllNum] = { -1 };
    int mDamageAnimation = 0;
    float mDamageAnimCoolTime = 0.2f;
    float mDamageTime = 0.5f;
    bool mDamageAnimationFlag = FALSE;
    bool DirFlag = FALSE;
    // 体力
    int hp=0;

};