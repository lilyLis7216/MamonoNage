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