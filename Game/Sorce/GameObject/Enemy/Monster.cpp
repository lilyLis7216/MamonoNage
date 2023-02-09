#include "Monster.h"

Monster::Monster()
    : GameObj(ObjTag::Enemy)
    , speed(0)
    , hp(0)
{
}

Monster::Monster(VECTOR pos)
    : GameObj(ObjTag::Enemy,pos)
    , speed(0)
    , hp(0)
{
}

Monster::~Monster()
{
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
    if (KeyMgr::KeyStatusD())
    {
        mDamageAnimationFlag = TRUE;
        ShakeFlag = TRUE;
    }
    else
    {
        mDamageAnimationFlag = FALSE;
        ShakeFlag = FALSE;
    }

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
            alive = FALSE;
        }
    }
}

