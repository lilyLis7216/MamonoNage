#include "Collision.h"
#include "../GameObject/Player/Player.h"
#include"../GameObject/GameObj.h"
#include"MapCollision.h"

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

VECTOR CalcPushBack(Collision* colObj, MapCollision* mapCol)
{
    VECTOR pushBack = { 0,0,0 };
    colObj->SetOnGround(false);
    //オブジェクトBOXの頂点座標//
    int objLX = (int)(colObj->ColGetPos().x -colObj->ColGetScale().x);
    int objLY = (int)(colObj->ColGetPos().y -colObj->ColGetScale().y);
    int objRX = (int)(colObj->ColGetPos().x + colObj->ColGetScale().x);
    int objRY = (int)(colObj->ColGetPos().y + colObj->ColGetScale().y);

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

            if (!mapCol->HitBlockType(jx,iy,0))
            {
                if (abs(bx) < abs(by))
                {
                    if (mapCol->HitBlockType(jx - 1, iy, 0) ||
                        mapCol->HitBlockType(jx + 1, iy, 0))
                    {
                        pushBack.x = (float)bx;
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
        }
    }
    return pushBack;
}
