#pragma once

#include "Monster.h"

/// <summary>
/// ゴーレムクラス（Monster継承）
/// </summary>
class Golem final : public Monster
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Golem();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Golem();

    // 走りアニメーション設定
    void MoveAnimation(float _deltaTime);
    //被ダメージアニメーション設定
    void DamageAnimation(float _deltaTime);
    //攻撃アニメーション設定
    void AttackAnimation(float _deltaTime);
    //アニメーションコントロール
    void AnimationControl();

    /// <summary>
    /// ゴーレムの更新処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    void Update(float _deltaTime) override;

    /// <summary>
    /// ゴーレムの描画処理
    /// </summary>
    void Draw(int, int) override;

private:
};