#include "Bullet.h"
#include "Player.h"
#include <math.h>

Bullet::Bullet(Player* player)
    : GameObj(ObjTag::Bullet)
    , mRotation(0)
    , mMovePower(5)
    , mBulletVX(0)
    , mBulletVY(0)
    , mBulletPower{ 0,0 }
    , bulletPos{}
    , mBulletNumber(0)
{
    if (handle = -1) 
    {
        handle = LoadGraph("../asset/player/player.png");
    }
    pos.x = player->GetPos().x;
    pos.y = player->GetPos().y + -10;
}

Bullet::~Bullet()
{
}

void Bullet::BulletAngleSet(double mAngle)
{
    mBulletVX = mMovePower * cosf(mAngle * DX_PI);
    mBulletVY = -mMovePower * sinf(mAngle * DX_PI);

    mBulletPower.x = (float)mBulletVX;
    mBulletPower.y = (float)mBulletVY;
    if (rightDir)
    {
        mBulletPower.x = -mBulletVX;
    }
    else
    {
        mBulletPower.x = mBulletVX;
    }
}

void Bullet::BulletMove()
{
    if (onGround)
    {
        mBulletPower.x = 0;
        mBulletPower.y = 0;
    }
    else
    {
        if (rightDir)
        {
            pos = VAdd(pos, mBulletPower);
        }
        if (!rightDir)
        {
            pos = VAdd(pos, mBulletPower);
        }
        pos = VAdd(pos, mBulletPower);
        mBulletPower.y += 0.2f;
    }
}

void Bullet::Update(float deltaTime)
{
    BulletMove();
}

void Bullet::Draw(int offSetX, int offSetY)
{
    DrawRotaGraph((int)pos.x - offSetX, (int)pos.y - offSetY, 0.1f, mRotation, handle, alive, rightDir);
    mRotation++;
}

void Bullet::BulletNumberAdd(int ButtonStatus)
{
    if (ButtonStatus == 3)
    {
        mBulletNumber++;
    }
}
