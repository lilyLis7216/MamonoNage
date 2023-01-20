#include "Background.h"

/// <summary>
/// コンストラクタ
/// </summary>
Background::Background()
    : pos(VGet(0,0,0))
    , drawX(0)
    , drawY(0)
{
    // 背面レイヤー読み込み
    back = LoadGraph("../asset/background/R2_distantView.png");

    // 中央レイヤー読み込み
    mid = LoadGraph("../asset/background/R2_middleView.png");

    // 前面レイヤー読み込み
    front = LoadGraph("../asset/background/R2_foreGround.png");
}

/// <summary>
/// デストラクタ
/// </summary>
Background::~Background()
{
    DeleteGraph(back);
    DeleteGraph(mid);
    DeleteGraph(front);
}

/// <summary>
/// 背景の描画処理
/// </summary>
/// <param name="scrX"></param>
/// <param name="scrY"></param>
void Background::Draw(int scrX, int scrY)
{
    //----スクロール座標反映----//
    drawX = (int)pos.x - scrX;
    drawY = (int)pos.y - scrY;

    //----背面レイヤー----//
    DrawGraph(drawX % ScreenW, drawY, back, TRUE);
    DrawGraph(drawX % ScreenW + ScreenW, drawY, back, TRUE);

    //----中央レイヤー----//
    DrawGraph(drawX * 2 % ScreenW, drawY, mid, TRUE);
    DrawGraph(drawX * 2 % ScreenW + ScreenW, drawY, mid, TRUE);

    //----前面レイヤー----//
    DrawGraph(drawX * 3 % ScreenW, drawY, front, TRUE);
    DrawGraph(drawX * 3 % ScreenW + ScreenW, drawY, front, TRUE);
}
