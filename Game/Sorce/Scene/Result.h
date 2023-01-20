#pragma once

#include "SceneBase.h"

class Result : public SceneBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Result();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Result();

    /// <summary>
    /// リザルトシーンの更新処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    /// <returns>現在のシーンのポインタ</returns>
    SceneBase* Update(float _deltaTime) override;

    /// <summary>
    /// リザルトシーンの描画処理
    /// </summary>
    void Draw() override;
};