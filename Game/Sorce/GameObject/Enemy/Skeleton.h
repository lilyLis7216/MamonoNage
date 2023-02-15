#pragma once

#include "Monster.h"

//移動スピード
const float SKELETONSPEED = 100.0f;

/// <summary>
/// スケルトンクラス（Monster継承）
/// </summary>
class Skeleton final : public Monster
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Skeleton();
    Skeleton(VECTOR pos);

    /// <summary>
   /// デストラクタ
   /// </summary>
    ~Skeleton();

    /// <summary>
    /// スケルトンのアップデート
    /// </summary>
    /// <param name="_deltaTime"></param>
    void Update(float _deltaTime)override;

    // <summary>
    /// スケルトンの描画処理
    /// </summary>
    void Draw(int offSetX, int offSetY) override;

};

