#pragma once

#include "DxLib.h"

class Collision
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Collision();

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Collision(const VECTOR& objPos, const VECTOR& objScale, const float objRad);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Collision();

    void Move(const VECTOR& objPos) { colPos = objPos; }

    VECTOR ColGetPos() { return colPos; }
    VECTOR ColGetScale() { return colScale; }
    float ColGetRad() { return colRad; }

    void SetOnGround(bool onground) { onGround= onground; }
    bool OnGround() { return onGround; }
private:


    VECTOR colPos;

    VECTOR colScale;

    float colRad;

    bool onGround;
};



VECTOR CalcPushBack(class Collision* colObj, class MapCollision* mapCol);