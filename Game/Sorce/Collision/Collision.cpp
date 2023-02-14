#include "Collision.h"
#include "../GameObject/Player/Player.h"
#include"../GameObject/GameObj.h"
#include"MapCollision.h"
#include "DxLib.h"
Collision::Collision()
    : colPos()
    , colScale()
    , colRad()
    ,onGround(false)
{
}

Collision::Collision(const VECTOR& objPos, const VECTOR& objScale, const float objRad)
    :colPos(objPos)
    ,colScale(objScale)
    ,colRad(objRad)
    ,onGround(false)
{
}

Collision::~Collision()
{
}

bool Collision::RectToCircle(VECTOR& Rect, float RectW, float RectH, const VECTOR& Circle, float CircleR)
{
    // 矩形の4つの頂点と円の中心点との距離を計算
    float rectLeft = Rect.x - RectW / 2;
    float rectTop = Rect.y - RectH / 2;
    float rectRight = Rect.x + RectW / 2;
    float rectBottom = Rect.y + RectH / 2;

    float closestX = (Circle.x < rectLeft) ? rectLeft : (Circle.x > rectRight ? rectRight : Circle.x);
    float closestY = (Circle.y < rectTop) ? rectTop : (Circle.y > rectBottom ? rectBottom : Circle.y);

    // 矩形の最近接点と円の中心点の距離を計算
    float distance = sqrt((Circle.x - closestX) * (Circle.x - closestX) +
        (Circle.y - closestY) * (Circle.y - closestY));

    // 距離が半径以下であるかどうかを判定
    if (distance <= CircleR) {
        return TRUE; //当たっている
    }
    else {
        return FALSE;// 当たっていない
    }
}


bool Collision::CircleToCircle(VECTOR& objPos,float objPosR,const VECTOR& objPos2,float objPos2R)
{
    float dx = objPos2.x - objPos.x;
    float dy = objPos2.y - objPos.y;
    float dist = sqrt(dx * dx + dy * dy);
    return dist < objPosR + objPos2R;
}


VECTOR CalcPushBack(Collision* colObj, MapCollision* mapCol,int vy)
{
    VECTOR pushBack = { 0,0,0 };
    colObj->SetOnGround(false);

    //オブジェクトBOXの頂点座標//
    int objLX = (int)(colObj->ColGetPos().x -colObj->ColGetScale().x/2.0f);
    int objLY = (int)(colObj->ColGetPos().y -colObj->ColGetScale().y/2.0f);
    int objRX = (int)(colObj->ColGetPos().x + colObj->ColGetScale().x/2.0f);
    int objRY = (int)(colObj->ColGetPos().y + colObj->ColGetScale().y/1.5f);

    //現在のタイル位置//
    int tileLX = objLX / BOX_WIDTH;
    int tileLY = objLY / BOX_HEIGHT;
    int tileRX = objRX / BOX_WIDTH;
    int tileRY = objRY / BOX_HEIGHT;

    for (int iy = tileLY; iy < tileRY + 1; iy++)
    {
        for (int jx = tileLX; jx < tileRX + 1; jx++)
        {
            //当たり判定BOXの頂点座標//
            int boxLX = jx * BOX_WIDTH;
            int boxLY = iy * BOX_HEIGHT;
            int boxRX = boxLX + BOX_WIDTH;
            int boxRY = boxLY + BOX_HEIGHT;

            //押し出し処理//
            int bx1 = boxLX - objRX;
            int bx2 = boxRX - objLX;
            int by1 = boxLY - objRY;
            int by2 = boxRY - objLY;

            //押し出し方向を決める//
            int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
            int by = (abs(by1) < abs(by2)) ? by1 : by2;

            
            if (mapCol->HitBlockType(jx, iy, 1))
            {
                if (abs(bx) < abs(by))
                {
                    if (mapCol->HitBlockType(jx - 1, iy, 0) ||
                        mapCol->HitBlockType(jx + 1, iy, 0))
                    {
                        pushBack.x = (float)bx;
                        pushBack.y = 0.0f;
                    }
                }
                else
                {
                    if (mapCol->HitBlockType(jx, iy - 1, 0) ||
                        mapCol->HitBlockType(jx, iy + 1, 0))
                    {
                        pushBack.y = (float)by;
                        if (by <= 0)
                        {
                            colObj->SetOnGround(true);
                        }
                    }
                }
            }
            if (mapCol->HitBlockType(jx, iy, 2))
            {
                if (abs(bx) > abs(by))
                {
                    if (vy >= 0 && by <= 0)
                    {
                        pushBack.y = (float)by;
                        colObj->SetOnGround(true);
                    }
                    else
                    {
                        pushBack.y = 0;
                    }
                }
                else
                {
                    pushBack.x = 0;
                }
            }
        }
    }
    return pushBack;
}

