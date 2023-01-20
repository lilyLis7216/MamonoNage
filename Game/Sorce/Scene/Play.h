#pragma once

#include "SceneBase.h"

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
};