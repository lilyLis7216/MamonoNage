#pragma once

#include "Monster.h"


//蝙蝠のサイズ
const int XSize = 64;
const int YSize = 64;

//アニメーションの共通要素(被ダメージはXNumが２)
const int XNum = 4;
const int YNum = 1;

//移動アニメーション
const int MoveAllNum = 4;
//攻撃アニメーション関連
const int AttackAllNum = 4;
//被ダメージアニメーション
const int DamageAllNum = 2;
const int DamageXNum = 2;


/// <summary>
/// コウモリクラス（Monster継承）
/// </summary>
class Bat final : public Monster
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Bat();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Bat();

    /// <summary>
   /// 初期位置代入
   /// </summary>
   /// <param name="Pos"></csvから初期位置を引っ張ってくる>
    void Init(VECTOR Pos);
    
    /// <summary>
    /// コウモリの更新処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    void Update(float _deltaTime) override;

    /// <summary>
    /// コウモリの描画処理
    /// </summary>
    void Draw(int, int) override;

private:

    //動きモーション
    int mMove[MoveAllNum] = { -1 };
    int mMoveAnimation = 0;
    float mMoveAnimCoolTime = 2.0f;

    //攻撃モーション
    int mAttack[AttackAllNum] = { -1 };
    int mAttackAnimation = 0;
    float mAttackAnimCoolTime = 2.0f;

    //被ダメ―ジモーション
    int mDamage[DamageAllNum] = { -1 };
    int mDamageAnimation = 0;
    float mDamageAnimCoolTime = 2.0f;
};