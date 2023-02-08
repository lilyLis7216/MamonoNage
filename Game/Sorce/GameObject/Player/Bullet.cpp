#include "Bullet.h"
#include "../../Manager/BulletMgr.h"
#include "Player.h"
#include <math.h>
#include"../../Collision/Collision.h"
#include"../../Collision/MapCollision.h"

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

    collision = new Collision(pos, VGet(32, 32, 0), 0.0f);
}

Bullet::~Bullet()
{
}

void Bullet::BulletAngleSet(double mAngle)
{
    mBulletVX = mMovePower * cosf(mAngle * DX_PI_F);
    mBulletVY = -mMovePower * sinf(mAngle * DX_PI_F);

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
    MapColEnter();
}

void Bullet::Draw(int offSetX, int offSetY)
{
    DrawRotaGraph((int)pos.x - offSetX, (int)pos.y - offSetY, 0.1f, mRotation, handle, alive, rightDir);
    mRotation++;
}

void Bullet::OnCollisionEnter(GameObj* other)
{
    ObjTag tag = other->GetTag();

    //�G���G�Ƃ̏Փ�
    if (tag == ObjTag::Enemy)
    {
        //�v���C���[�̒e�ƓG�̓����蔻��
        if (collision->CircleToCircle(pos,32,other->GetPos(),32))
        {
            alive = FALSE;
        }
    }
}

void Bullet::MapColEnter()
{
    VECTOR ret = CalcPushBack(collision, MapCollision::GetMapCol());
    pos = VAdd(pos, ret);
    
    onGround = collision->OnGround();
    if (onGround) { mRotation = 0; }
    ColUpdate();
}
