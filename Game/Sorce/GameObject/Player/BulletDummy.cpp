#include "BulletDummy.h"
#include "Player.h"

BulletDummy::BulletDummy(Player* player)
    : GameObj(ObjTag::BulletDummy)
    , mAngle(0)
    , AddAngle(0.3)
    , mRotation(0)
{
    if (handle = -1) 
    {
        handle = LoadGraph("../asset/player/arrow.png");
    }
    rightDir = player->GetDir();
    pos = player->GetPos();
}

BulletDummy::~BulletDummy()
{
    DeleteGraph(handle);
    handle = -1;
}

void BulletDummy::AddRadian(float _deltaTime)
{
    if (mAngle < 0)
    {
        mAngle = 0.01;
        AddAngleChange();
    }
    else if (mAngle > 0.5)
    {
        mAngle = 0.49;
        AddAngleChange();
    }
    mAngle += AddAngle * _deltaTime;
}

void BulletDummy::AddAngleChange()
{
    AddAngle = AddAngle * -1;
}

void BulletDummy::Update(float deltaTime)
{
}

void BulletDummy::Draw(int offSetX, int offSetY)
{
    if (alive && rightDir) {
        DrawRotaGraph(((int)pos.x - 100) - offSetX, ((int)pos.y - 100) - offSetY, 1, mAngle * DX_PI, handle, alive, rightDir);
    }
    else if (alive && !rightDir)
    {
        DrawRotaGraph(((int)pos.x + 100) - offSetX, ((int)pos.y - 100) - offSetY, 1, -mAngle * DX_PI, handle, alive, rightDir);
    }
    /*unsigned int Color;

    Color = GetColor(255, 255, 255);
    DrawFormatString(0, 0, Color, "ïœêî i ÇÃílÇÕ %f Ç≈Ç∑", mAngle);*/
}
