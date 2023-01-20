#pragma once

#include "SceneBase.h"
#include "DxLib.h"

/// <summary>
/// タイトルシーン（SceneBaseを継承）
/// </summary>
class Title : public SceneBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Title();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Title();

    /// <summary>
    /// タイトルシーンの更新処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    /// <returns>現在のシーンのポインタ</returns>
    SceneBase* Update(float _deltaTime) override;

    /// <summary>
    /// タイトルシーンの描画処理
    /// </summary>
    void Draw() override;

private:
    // 透明度
    int fadein;

    // 背景座標
    VECTOR bgPos;

    // 背景
    class Background* bg;

    // 背景スクロール速度
    float bgScrollSpeed;

    // 不透明度最大値
    const int maxFadein = 255;

    // フェード速度
    const int fadeSpeed = 5;

};