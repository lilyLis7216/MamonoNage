#pragma once

#include "Monster.h"

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
    /// コウモリの更新処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    void Update(float _deltaTime) override;

    /// <summary>
    /// コウモリの描画処理
    /// </summary>
    void Draw(int, int) override;

private:
};