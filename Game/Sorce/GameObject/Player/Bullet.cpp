#include "Bullet.h"
#include "../../Manager/BulletMgr.h"
#include "Player.h"
#include"../Enemy/Monster.h"
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

    if (player->GetDir()) {
        pos.x = player->GetPos().x - 110;
    }
    else {
        pos.x = player->GetPos().x + 110;
    }
    pos.y = player->GetPos().y + -50;

    handle = BulletMgr::GetHandle();

    collision = new Collision(pos, VGet(32, 32, 0), 0.0f);
}

Bullet::Bullet(Monster* monster)
:GameObj(ObjTag::Bullet)
, mRotation(0)
, mMovePower(5)
, mBulletVX(0)
, mBulletVY(0)
, mBulletPower{ 0,0 }
, bulletPos{}
, mBulletNumber(0)
{
    //“–‚½‚Á‚½‘ŠŽè‚É‡‚í‚¹‚Äbullet‚ð¶¬
    if (monster->GetemyType() == 1) {
        handle = BulletMgr::GetSlimeHandle();
    }
    if(monster->GetemyType() == 2){
        handle = BulletMgr::GetBatHandle();
    }
    if (monster->GetemyType() == 3) {
        handle = BulletMgr::GetSkeletonHandle();
    }
    pos = monster->GetPos();
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
        if (handle == BulletMgr::GetGoastHandle())
        {
            alive = FALSE;
        }
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
    DrawRotaGraph((int)pos.x - offSetX, (int)pos.y - offSetY, 2.0f, mRotation, handle, alive, rightDir);
    mRotation+=0.1;
}

void Bullet::OnCollisionEnter(GameObj* other)
{
    ObjTag tag = other->GetTag();

    //ŽG‹›“G‚Æ‚ÌÕ“Ë
    if (tag == ObjTag::Enemy)
    {
        //ƒvƒŒƒCƒ„[‚Ì’e‚Æ“G‚Ì“–‚½‚è”»’è
        if (collision->CircleToCircle(pos,32,other->GetPos(),32))
        {
            //alive = FALSE;
        }
    }
    //ƒvƒŒƒCƒ„[‚Æ’e‚ÌÕ“Ë
    if (tag == ObjTag::Player)
    {
        //ƒvƒŒƒCƒ„[‚Ì’e‚Æ“G‚Ì“–‚½‚è”»’è
        if (collision->CircleToCircle(pos, 32, other->GetPos(), 100))
        {
            if (onGround) {
                BulletMgr::AddBulletNum(handle);
                alive = FALSE;
            }
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
