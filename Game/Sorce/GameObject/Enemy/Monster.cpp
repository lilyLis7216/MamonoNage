#include "Monster.h"

Monster::Monster()
    : GameObj(ObjTag::Enemy)
    , speed(0)
    , hp(0)
{
}

Monster::Monster(BulletMgr::BulletType bulletType, VECTOR pos)
    : GameObj(ObjTag::Enemy,pos)
    , emyType(bulletType)
  
{
    collision = new Collision(pos, VGet(EnemyXSize, EnemyYSize, 0), 0.0f);
}

Monster::~Monster()
{
}

void Monster::Move(float _deltaTime)
{
    if (rightDir)
    {
        pos.x -= speed * _deltaTime;
    }
    else if (!rightDir)
    {
        pos.x += speed * _deltaTime;
    }

    mEmyVy += gravity;
    if (mEmyVy > maxFallSpeed)
    {
        mEmyVy = maxFallSpeed;
    }
    pos.y += mEmyVy;
}

void Monster::DirReverse(VECTOR ret)
{
    if (ret.x>0)
    {
        rightDir = FALSE;
    }
    if (ret.x<0)
    {
        rightDir = TRUE;
    }

    if (onFirstEmyGround == TRUE && ret.y==0)
    {
        if (rightDir) {
            rightDir = FALSE;
            pos.x = tmpPos.x + 5;
            pos.y = tmpPos.y;
        }
        else if (!rightDir) {
            rightDir = TRUE;
            pos.x = tmpPos.x - 5;
            pos.y = tmpPos.y;
        }
    }
    tmpPos = pos;
    
}

void Monster::MoveAnimation(float _deltaTime)
{
    mMoveAnimCoolTime -= _deltaTime;
    if (mMoveAnimCoolTime <= 0.0f)
    {
        mMoveAnimation++;
        if (mMoveAnimation >= EnemyMoveAllNum)
        {
            mMoveAnimation = 0;
        }
        mMoveAnimCoolTime = 0.1f;
        mMoveAnimation %= EnemyMoveAllNum;
    }
}

void Monster::DamageAnimation(float _deltaTime)
{
    mDamageAnimCoolTime -= _deltaTime;
    if (mDamageAnimCoolTime <= 0.0f)
    {
        mDamageAnimation++;
        if (mDamageAnimation >= EnemyDamageAllNum)
        {
            mDamageAnimation = 0;
        }
        mDamageAnimCoolTime =0.3f;
        mDamageAnimation %= EnemyDamageAllNum;
        
    }
    if (mDamageAnimationFlag&& rightDir)
    {   
        EffectMgr::EffectA(_deltaTime, pos.x, pos.y);
        pos.x+=5;
        mDamageTime -= _deltaTime;
        if (mDamageTime < 0) 
        {
            mDamageAnimationFlag = FALSE;
            Bullet* bullet = new Bullet(this);
            bullet->SetPos(this->GetPos());
         
            GameObjMgr::Entry(bullet);
            EffectMgr::SetAEffectFlag(FALSE);
            alive = FALSE;
        }
    }
    else if(mDamageAnimationFlag && !rightDir) 
    {            
        EffectMgr::EffectA(_deltaTime, pos.x, pos.y);
        pos.x-=5;
        mDamageTime -= _deltaTime;
        if (mDamageTime < 0)
        {
            mDamageAnimationFlag = FALSE;
            Bullet* bullet = new Bullet(this);
            bullet->SetPos(this->GetPos());

            GameObjMgr::Entry(bullet);
            EffectMgr::SetAEffectFlag(FALSE);
            alive = FALSE;
        }
    }
}

void Monster::AttackAnimation(float _deltaTime)
{
    if (KeyMgr::KeyStatusA())
    {
        mAttackAnimationFlag = TRUE;
    }
    else
    {
        mAttackAnimationFlag = FALSE;
    }
    mAttackAnimCoolTime -= _deltaTime;
    if (mAttackAnimCoolTime <= 0.0f)
    {
        mAttackAnimation++;
        if (mAttackAnimation >= EnemyAttackAllNum)
        {
            mAttackAnimation = 0;
        }
        mAttackAnimCoolTime = 0.2f;
        mAttackAnimation %= EnemyAttackAllNum;
    }
}

void Monster::AnimationControl()
{
    if (mDamageAnimationFlag)
    {
        handle = mDamage[mDamageAnimation];
    }
    else if (mAttackAnimationFlag)
    {
        handle = mAttack[mAttackAnimation];
    }
    else
    {
        handle = mMove[mMoveAnimation];
    }
}

void Monster::OnCollisionEnter(GameObj* other)
{
    ObjTag tag = other->GetTag();

    //’e‚Æ‚ÌÕ“Ë
    if (tag == ObjTag::Bullet)
    {
        //ƒvƒŒƒCƒ„[‚Ì’e‚Æ“G‚Ì“–‚½‚è”»’è
        if (collision->CircleToCircle(pos, 32, other->GetPos(), 32))
        {   
            mDamageAnimationFlag = TRUE;
            ShakeFlag = TRUE;
            EffectMgr::SetAEffectFlag(TRUE);
            if (pos.x-other->GetPos().x > 0&&DirFlag == FALSE)
            {
                rightDir = TRUE;
                DirFlag = TRUE;
            }
            else if(pos.x - other->GetPos().x < 0 && DirFlag == FALSE)
            {
                rightDir = FALSE;
                DirFlag = TRUE;
            }
            
        }
    }
}

void Monster::MapColEnter()
{
    VECTOR ret = CalcPushBack(collision, MapCollision::GetMapCol(), mEmyVy);
    pos = VAdd(pos, ret);
    DirReverse(ret);
    onGround = collision->OnGround();
    if (onGround) { onFirstEmyGround = TRUE; }
    ColUpdate();
}

