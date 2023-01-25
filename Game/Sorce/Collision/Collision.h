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

private:


    VECTOR colPos;

    VECTOR colScale;

    float colRad;
};



VECTOR CalcPushBack(class Collision* colObj, class MapCollision* mapCol);