#include "Monster.h"

Monster::Monster()
    : GameObj(ObjTag::Enemy)
    , speed(0)
    , hp(0)
{
}

Monster::Monster(BulletMgr::BulletType bulletType, VECTOR pos)
    : GameObj(ObjTag::Enemy,pos)
    ,emyType(bulletType)
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

    //�e�Ƃ̏Փ�
    if (tag == ObjTag::Bullet)
    {
        //�v���C���[�̒e�ƓG�̓����蔻��
        if (collision->CircleToCircle(pos, 32, other->GetPos(), 32))
        {
            BulletMgr::AddBulletNum(emyType);
            alive = FALSE;
        }
    }
}

