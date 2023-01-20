#include "Scroll.h"

/// <summary>
/// コンストラクタ
/// </summary>
Scroll::Scroll()
    : scrollX(0)
    , scrollY(0)
    , dx(0)
    , dy(0)
{
    scrMaxX = 40 * 162 - 1920;
    scrMaxY = 40 * 58 - 1080;
    scrMinX = 0;
    scrMinY = 0;
}

/// <summary>
/// デストラクタ
/// </summary>
Scroll::~Scroll()
{
}

/// <summary>
/// スクロールの更新処理
/// </summary>
/// <param name="_deltaTime">1フレームの経過時間</param>
/// <param name="plyPos">プレイヤーの座標</param>
void Scroll::Update(float _deltaTime, VECTOR& plyPos)
{
    dx = dy = 0;

    //---プレイヤー押し戻し処理---//
    //右にスクロールする座標を超えたら
    if (plyPos.x + 64 > scrollX + scrMaxW)
    {
        //左に押し戻す
        dx = plyPos.x + 64 - (scrollX + scrMaxW);
    }

    //下スクロール
    if (plyPos.y + 64 > scrollY + scrMaxH)
    {
        dy = plyPos.y + 64 - (scrollY + scrMaxH);
    }

    //左スクロール
    if (plyPos.x - 64 < scrollX + scrMinW)
    {
        dx = plyPos.x - 64 - (scrollX + scrMinW);
    }

    //上スクロール
    if (plyPos.y - 64 < scrollY + scrMinH)
    {
        dy = plyPos.y - 64 - (scrollY + scrMinH);
    }

    //押し戻しX
    scrollX += dx;

    //押し戻しY
    scrollY += dy;

    //---スクロール座標最大値処理---//
    //右スクロール座標最大値まできたら
    if (scrollX > scrMaxX)
    {
        //スクロール停止
        scrollX = scrMaxX;
    }
    //左スクロール
    else if (scrollX < scrMinX)
    {
        scrollX = scrMinX;
    }

    //下スクロール
    if (scrollY > scrMaxY)
    {
        scrollY = scrMaxY;
    }
    //上スクロール
    else if (scrollY < scrMinY)	
    {
        scrollY = scrMinY;
    }
}

/// <summary>
/// スクロールの描画オフセットXを取得
/// </summary>
/// <returns>X方向オフセット</returns>
int Scroll::GetDrawOffSetX()
{
    return static_cast<int>(scrollX);
}

/// <summary>
/// スクロールの描画オフセットYを取得
/// </summary>
/// <returns>Y方向オフセット</returns>
int Scroll::GetDrawOffSetY()
{
    return static_cast<int>(scrollY);
}
