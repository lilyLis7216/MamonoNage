#include "Player.h"
#include"../../Collision/Collision.h"
#include"../../Collision/MapCollision.h"
#include"../../Manager/KeyMgr.h"
#include"../../Manager/BulletMgr.h"

Player::Player()
    : GameObj(ObjTag::Player)
    , playerVy(0)
    , jumpFlag(false)
    , input(false)
    , jumpButtonCount()
    , mAnimation()
    , mIdle{}
    , mIdleAnimation(0)
    , mIdleAnimCoolTime(1.0f)
    , mRun{}
    , mRunAnimation(0)
    , mRunAnimCoolTime(0.0f)
    , mJump{}
    , mJumpAnimation(0)
    , mJumpAnimCoolTime(0.2f)
    , mThrow{}
    , mThrowAnimation(0)
    , mThrowAnimCoolTime(0.2f)
    , mThrowAnimationFlag(false)
    , mPrepa{}
    , mPrepaAnimation(0)
    , mPrepaAnimCoolTime(1.0f)
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
    if (!(handle == mDamage[mDamageAnimation])) 
    {
        DrawRotaGraph((int)pos.x - offSetX, (int)pos.y - offSetY, 1.5, 0, handle, TRUE, rightDir);
    }
    if (handle == mDamage[mDamageAnimation] && mDamageAnimation)
    {
        DrawRotaGraph((int)pos.x - offSetX, (int)pos.y - offSetY, 1.5, 0, handle, TRUE, rightDir);
    }
}

void Player::Init()
{
    // ƒvƒŒƒCƒ„[‚Ì‰ŠúˆÊ’u‚Ì‘ã“ü
    pos.x = FirstPosX;
    pos.y = FirstPosY;

    // ƒvƒŒƒCƒ„[‰æ‘œ‚Ì“Ç‚Ýž‚Ý
    LoadDivGraph("../asset/player/_idle.png", IdleAllNum, IdleXNum, IdleYNum, XSize, YSize, mIdle, TRUE);
    LoadDivGraph("../asset/player/_run.png", RunAllNum, RunXNum, RunYNum, XSize, YSize, mRun, TRUE);
    LoadDivGraph("../asset/player/_jump.png", JumpAllNum, JumpXNum, JumpYNum, XSize, YSize, mJump, TRUE);
    LoadDivGraph("../asset/player/_prepa.png", PrepaAllNum, PrepaXNum, PrepaYNum, XSize, YSize, mPrepa, TRUE);
    LoadDivGraph("../asset/player/_throw.png", ThrowAllNum, ThrowXNum, ThrowYNum, XSize, YSize, mThrow, TRUE);
    LoadDivGraph("../asset/player/_damage.png", 2, 2, 1, XSize, YSize, mDamage, TRUE);
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

    GetHitKeyStateAllEx(key);
    if (onGround)
    {
        if (key[KEY_INPUT_J] == 1)
        {
            jumpFlag = true;
        }
        else if (key[KEY_INPUT_J] > 1 || key[KEY_INPUT_J] == -1)
        {
            jumpFlag = false;
        }
        if (jumpFlag)
        {
            playerVy = -jumpPower;
            jumpFlag = false;
        }
        else if (playerVy > 0)
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

void Player::OnCollisionEnter(GameObj* other)
{
    ObjTag tag = other->GetTag();

    //ŽG‹›“G‚Æ‚ÌÕ“Ë
    if (tag == ObjTag::Enemy)
    {
        //ƒvƒŒƒCƒ„[‚ÆŽG‹›“G‚Ì“–‚½‚è”»’è
        if (collision->RectToCircle(pos,YSize,XSize, other->GetPos(), 32))
        {
            //alive = FALSE;
        }
    }

    //’e‚Æ‚ÌÕ“Ë
    if (tag == ObjTag::Bullet)
    {
        //ƒvƒŒƒCƒ„[‚Æ’e‚Ì“–‚½‚è”»’è
        if (collision->RectToCircle(pos, YSize, XSize, other->GetPos(), 32))
        {
            //alive = FALSE;
        }
    }

    //ŽG‹›“G‚Æ‚ÌÕ“Ë
    if (tag == ObjTag::Flag)
    {
        //ƒvƒŒƒCƒ„[‚ÆŽG‹›“G‚Ì“–‚½‚è”»’è
        if (collision->RectToCircle(pos, YSize, XSize, other->GetPos(), 32))
        {
            PlySceneEndFlag = TRUE;
        }
    }
}

void Player::MapColEnter()
{
    VECTOR ret = CalcPushBack(collision, MapCollision::GetMapCol(),playerVy);
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

void Player::ThrowPrepaAnimation(float _deltaTime)
{
    mPrepaAnimCoolTime -= _deltaTime;
    if (mPrepaAnimCoolTime <= 0.0f)
    {
        mPrepaAnimation++;
        if (mPrepaAnimation >= PrepaAllNum)
        {
            mPrepaAnimation = 0;
        }
        mPrepaAnimCoolTime = 0.6f;
        mPrepaAnimation %= PrepaAllNum;
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
        mThrowAnimCoolTime = 0.2f;
        mThrowAnimation %= ThrowAllNum;

        if (mThrowAnimation == ThrowAllNum - 1)
        {
            mThrowAnimationFlag = false;
            mThrowAnimation = 0;
        }
    }

    // “Š‚°ƒAƒjƒ[ƒVƒ‡ƒ“‚ªI‚í‚Á‚½‚çƒtƒ‰ƒO‚ð~‚ë‚·
}

void Player::JumpAnimation(float _deltaTime)
{
    if (!onGround)
    {
        mJumpAnimCoolTime -= _deltaTime;
        if (mJumpAnimCoolTime <= 0.3f)
        {
            mJumpAnimation++;
            if (mJumpAnimation >= JumpAllNum)
            {
                mJumpAnimation = 0;
            }
            mJumpAnimCoolTime = 0.5f;
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
    if (KeyMgr::KeyStatusD())
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
        mDamageAnimCoolTime = 0.1f;
        mDamageAnimation %= DamageAllNum;
    }
}

void Player::AnimationUpdate(float _deltaTime)
{
    IdleAnimation(_deltaTime);
    RunAnimation(_deltaTime);
    JumpAnimation(_deltaTime);
    DamageAnimation(_deltaTime);
    ThrowPrepaAnimation(_deltaTime);
    if (mThrowAnimationFlag) {ThrowAnimation(_deltaTime);}
    AnimationControl();
}

void Player::AnimationControl()
{
    if (mDamageAnimationFlag)
    {
        handle = mDamage[mDamageAnimation];

    }
    else if (mPrepaAnimationFlag)
    {
        handle = mPrepa[mPrepaAnimation];
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
    }
    else
    {
        handle = mIdle[mIdleAnimation];
    }
}
