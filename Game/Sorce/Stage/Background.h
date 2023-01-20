#pragma once

#include "DxLib.h"

// 画面横幅
const int ScreenW = 1920;

// 画面縦幅
const int ScreenH = 1080;

/// <summary>
/// 背景クラス
/// </summary>
class Background
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Background();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Background();

    /// <summary>
    /// 背景の描画処理
    /// </summary>
    /// <param name="scrX"></param>
    /// <param name="scrY"></param>
    void Draw(int scrX, int scrY);

private:
    // 背面レイヤー
    int back;

    // 中央レイヤー
    int mid;

    // 前面レイヤー
    int front;

    // 描画座標x
    int drawX;

    // 描画座標y
    int drawY;

    // 背景座標
    VECTOR pos;
};