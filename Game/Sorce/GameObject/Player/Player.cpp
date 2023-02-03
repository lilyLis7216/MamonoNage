#include "Player.h"
#include"../../Collision/Collision.h"
#include"../../Collision/MapCollision.h"
#include"../../Manager/KeyMgr.h"

Player::Player()
    : GameObj(ObjTag::Player)
    , playerVy(0)
    , jumpFlag(false)
    , onGround(false)
    , input(false)
    , jumpButtonCount()
    , mAnimation()
    , mIdle{}
    , mIdleAnimation(0)
    , mIdleAnimCoolTime(1.0f)
    , mRun{}
    , mRunAnimation(0)
    , mRunAnimCoolTime(0.2f)
    , mJump{}
    , mJumpAnimation(0)
    , mJumpAnimCoolTime(0.2f)
    , mThrow{}
    , mThrowAnimation(0)
    , mThrowAnimCoolTime(0.2f)
    , mThrowAnimationFlag(false)
{
    collision = new Collision(pos, VGet(XSize, YSize, 0), 0.0f);
}

Player::~Player()
{
}

void Player::Update(float _deltaTime)
{
    Move(_deltaTime);
    AnimationUpdate(_deltaTime);
    MapColEnter();
}

void Player::Draw(int offSetX, int offSetY)
{
    DrawRotaGraph((int)pos.x - offSetX, (int)pos.y - offSetY, 1.5, 0, handle, TRUE, rightDir);
}

void Player::Init()
{
    // プレイヤーの初期位置の代入
    pos.x = FirstPosX;
    pos.y = FirstPosY;

    // プレイヤー画像の読み込み
    LoadDivGraph("../asset/player/_idle.png", IdleAllNum, IdleXNum, IdleYNum, XSize, YSize, mIdle,TRUE);
    LoadDivGraph("../asset/player/_run.png", RunAllNum, RunXNum, RunYNum, XSize, YSize, mRun,TRUE);
    LoadDivGraph("../asset/player/_jump.png", JumpAllNum, JumpXNum, JumpYNum, XSize, YSize, mJump, TRUE);
    LoadDivGraph("../asset/player/_throw.png", ThrowAllNum, ThrowXNum, ThrowYNum, XSize, YSize, mThrow, TRUE);
    LoadDivGraph("../asset/player/_damage.png", 2, 2, 1, XSize,YSize, mDamage, TRUE);

    //// コウモリ画像の読み込み
    /*LoadDivGraph("../asset/enemy/bat/_move.png", RunAllNum, RunXNum, RunYNum, EnemyXSize, EnemyYSize, mEnemyRun, TRUE);
    LoadDivGraph("../asset/enemy/bat/_attack.png", 4, 4, 1, EnemyXSize, EnemyYSize, mEnemyAttack, TRUE);
    LoadDivGraph("../asset/enemy/bat/_damage.png", 2, 2, 1, EnemyXSize, EnemyYSize, mEnemyDamage, TRUE);*/
     
    ////スケルトン画像の読み込み
    //LoadDivGraph("../asset/enemy/skeleton/skeleton_move.png", RunAllNum, RunXNum, RunYNum, EnemyXSize, EnemyYSize, mEnemyRun, TRUE);
    //LoadDivGraph("../asset/enemy/skeleton/skeleton_attack.png", 4, 4, 1, EnemyXSize, EnemyYSize, mEnemyAttack, TRUE);
    //LoadDivGraph("../asset/enemy/skeleton/skeleton_damage.png", 2, 2, 1, EnemyXSize, EnemyYSize, mEnemyDamage, TRUE);
}

void Player::Move(float _deltaTime)
{
    if (CheckHitKey(KEY_INPUT_RIGHT))
    {
        rightDir = false;
        pos.x += RunSpeed * _deltaTime;
    }
    else if (CheckHitKey(KEY_INPUT_LEFT))
    {
        rightDir = true;
        pos.x -= RunSpeed * _deltaTime;
    }

    if (onGround)
    {
        if (CheckHitKey(KEY_INPUT_J))
        {
            jumpFlag = true;
            if (jumpFlag)
            {
                playerVy = -jumpPower;
                jumpFlag = false;
            }
        }
        else
        {
            playerVy = 0;
        }
    }
    else if (!jumpFlag)
    {
        playerVy += gravity;
        if (playerVy > maxFallSpeed)
        {
            playerVy = maxFallSpeed;
        }
    }
    pos.y += playerVy;
}

void Player::MapColEnter()
{
    VECTOR ret = CalcPushBack(collision, MapCollision::GetMapCol());
    pos = VAdd(pos, ret);
    onGround = collision->OnGround();
    ColUpdate();
}

void Player::IdleAnimation(float _deltaTime)
{
    mIdleAnimCoolTime -= _deltaTime;
    if (mIdleAnimCoolTime <= 0.0f)
    {
        mIdleAnimation++;
        if (mIdleAnimation >= IdleAllNum)
        {
            mIdleAnimation = 0;
        }
        mIdleAnimCoolTime = 0.5f;
        mIdleAnimation %= IdleAllNum;
    }
}

void Player::RunAnimation(float _deltaTime)
{
    mRunAnimCoolTime -= _deltaTime;
    if (mRunAnimCoolTime <= 0.0f)
    {
        mRunAnimation++;
        if (mRunAnimation >= RunAllNum)
        {
            mRunAnimation = 0;
        }
        mRunAnimCoolTime = 0.2f;
        mRunAnimation %= RunAllNum;
    }
}

void Player::ThrowAnimation(float _deltaTime)
{
    mThrowAnimCoolTime -= _deltaTime;
    if (mThrowAnimCoolTime <= 0.0f)
    {
        mThrowAnimation++;
        mThrowAnimCoolTime = 0.3f;
        mThrowAnimation %= ThrowAllNum;

        if (mThrowAnimation == ThrowAllNum - 1)
        {
            mThrowAnimationFlag = false;
            mThrowAnimation = 0;
        }
    }

    // 投げアニメーションが終わったらフラグを降ろす
}

void Player::JumpAnimation(float _deltaTime)
{
    if (!onGround)
    {
        mJumpAnimCoolTime -= _deltaTime;
        if (mJumpAnimCoolTime <= 0.0f)
        {
            mJumpAnimation++;
            if (mJumpAnimation >= JumpAllNum)
            {
                mJumpAnimation = 0;
            }
            mJumpAnimCoolTime = 0.2f;
            mJumpAnimation %= JumpAllNum;
        }
    }
    else
    {
        mJumpAnimation = 0;
    }
}

void Player::DamageAnimation(float _deltaTime)
{
    if(KeyMgr::KeyStatusD())
    {
        mDamageAnimationFlag = TRUE;
    }
    else
    {
        mDamageAnimationFlag = FALSE;
    }

    mDamageAnimCoolTime -= _deltaTime;
    if (mDamageAnimCoolTime <= 0.0f)
    {
        mDamageAnimation++;
        if (mDamageAnimation >= DamageAllNum)
        {
            mDamageAnimation = 0;
        }
        mDamageAnimCoolTime = 1.0f;
        mDamageAnimation %= DamageAllNum;
    }
}
/// <summary>
/// 
/// </summary>
/// <param name="_deltaTime"></param>
//void Player::EnemyRunAnimation(float _deltaTime)
//{
//    mRunAnimCoolTime -= _deltaTime;
//    if (mRunAnimCoolTime <= 0.0f)
//    {
//        mEnemyRunAnimation++;
//        if (mEnemyRunAnimation >= EnemyRunAllNum)
//        {
//            mEnemyRunAnimation = 0;
//        }
//        mRunAnimCoolTime = 0.2f;
//        mEnemyRunAnimation %= EnemyRunAllNum;
//    }
//}
//
//void Player::EnemyDamageAnimation(float _deltaTime)
//{
//    if (KeyMgr::KeyStatusD())
//    {
//        mDamageAnimationFlag = TRUE;
//    }
//    else
//    {
//        mDamageAnimationFlag = FALSE;
//    }
//
//    mDamageAnimCoolTime -= _deltaTime;
//    if (mDamageAnimCoolTime <= 0.0f)
//    {
//        mEnemyDamageAnimation++;
//        if (mEnemyDamageAnimation >= EnemyDamageAllNum)
//        {
//            mEnemyDamageAnimation = 0;
//        }
//        mDamageAnimCoolTime = 1.0f;
//        mEnemyDamageAnimation %= EnemyDamageAllNum;
//    }
//}
//
//void Player::EnemyAttackAnimation(float _deltaTime)
//{
//    mIdleAnimCoolTime -= _deltaTime;
//    if (mIdleAnimCoolTime <= 0.0f)
//    {
//        mEnemyAttackAnimation++;
//        if (mEnemyAttackAnimation >= EnemyAttackAllNum)
//        {
//            mEnemyAttackAnimation = 0;
//        }
//        mIdleAnimCoolTime = 0.2f;
//        mEnemyAttackAnimation %= EnemyAttackAllNum;
//    }
//}

void Player::AnimationUpdate(float _deltaTime)
{
    IdleAnimation(_deltaTime);
    RunAnimation(_deltaTime);
    ThrowAnimation(_deltaTime);
    JumpAnimation(_deltaTime);
    DamageAnimation(_deltaTime);
    ////エネミー確認用
    //EnemyRunAnimation(_deltaTime);
    //EnemyDamageAnimation(_deltaTime);
    //EnemyAttackAnimation(_deltaTime);
    AnimationControl();
}

void Player::AnimationControl()
{
    if (mDamageAnimationFlag)
    {
        handle = mDamage[mDamageAnimation];
        ////エネミー用
        //handle = mEnemyDamage[mEnemyDamageAnimation];
    }
    else if (mThrowAnimationFlag)
    {
        handle = mThrow[mThrowAnimation];
    }
    else if (!onGround && !mThrowAnimationFlag)
    {
        handle = mJump[mJumpAnimation];
    }
    else if ((CheckHitKey(KEY_INPUT_RIGHT) && onGround) || (CheckHitKey(KEY_INPUT_LEFT) && onGround))
    {
        handle = mRun[mRunAnimation];
        ////エネミーアニメーション確認用
        //handle = mEnemyRun[mEnemyRunAnimation];
    }
    else
    {
        handle = mIdle[mIdleAnimation];
        //handle = mEnemyAttack[mEnemyAttackAnimation];
    }
}
