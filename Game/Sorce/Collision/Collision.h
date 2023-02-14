#pragma once

#include "DxLib.h"

class Collision
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Collision();

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Collision(const VECTOR& objPos, const VECTOR& objScale, const float objRad);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Collision();

    void Move(const VECTOR& objPos) { colPos = objPos; }

    VECTOR ColGetPos() { return colPos; }
    VECTOR ColGetScale() { return colScale; }
    float ColGetRad() { return colRad; }

    void SetOnGround(bool onground) { onGround= onground; }
    bool OnGround() { return onGround; }
  
    bool RectToCircle(VECTOR& Rect, float RectW, float RectH, const VECTOR& Circle, float CircleR);
    bool CircleToCircle(VECTOR& objPos, float objPosR, const VECTOR& objPos2, float objPos2R);        //
private:


    VECTOR colPos;

    VECTOR colScale;

    float colRad;

    bool onGround;
};


/// <summary>
/// 押し戻し量算出
/// </summary>
VECTOR CalcPushBack(class Collision* colObj, class MapCollision* mapCol, int vy = 0);