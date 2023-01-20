#pragma once

#include "DxLib.h"

/// <summary>
/// スクロールクラス
/// </summary>
class Scroll
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Scroll();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Scroll();

    /// <summary>
    /// スクロールの更新処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    /// <param name="plyPos">プレイヤーの座標</param>
    void Update(float _deltaTime, VECTOR& plyPos);

    /// <summary>
    /// スクロールの描画オフセットXを取得
    /// </summary>
    /// <returns>X方向オフセット</returns>
    int GetDrawOffSetX();

    /// <summary>
    /// スクロールの描画オフセットYを取得
    /// </summary>
    /// <returns>Y方向オフセット</returns>
    int GetDrawOffSetY();

private:
    //スクロールX
    float scrollX;

    //スクロールY
    float scrollY;

    //右方向へスクロール開始最大座標
    const float scrMaxW = 1920 / 40 * 20;

    //下方向へスクロール開始最大座標
    const float scrMaxH = 1080 / 40 * 25;

    //左方向へスクロール開始最小座標
    const float scrMinW = 1920 / 40 * 15;

    //上方向へスクロール開始最小座標
    const float scrMinH = 1080 / 40 * 15;

    //X方向スクロール最大値
    float scrMaxX;

    //Y方向スクロール最大値
    float scrMaxY;

    //X方向スクロール最小値
    float scrMinX;

    //Y方向スクロール最小値
    float scrMinY;

    //押し戻し座標
    float dx, dy; 
};