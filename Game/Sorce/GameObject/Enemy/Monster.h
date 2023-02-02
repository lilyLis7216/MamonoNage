#pragma once

#include "../GameObj.h"

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
    Monster(VECTOR pos);

    /// <summary>
    /// 仮想デストラクタ
    /// </summary>
    virtual ~Monster();

protected:
    // 速度
    float speed;

    // 移動アニメーション
    int moveAnim[4] = { -1 };

    // 攻撃アニメーション
    int atkAnim[4] = { -1 };

    // 被弾アニメーション
    int damageAnim[2] = { -1 };

    // 体力
    int hp;

};