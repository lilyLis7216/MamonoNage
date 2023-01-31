#include "Player.h"
#include"../../Collision/Collision.h"
#include"../../Collision/MapCollision.h"

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
    DrawRotaGraph((int)pos.x - offSetX, (int)pos.y - offSetY, 1, 0, handle, TRUE, rightDir);
}

void Player::Init()
{
    // �v���C���[�̏����ʒu�̑��
    pos.x = FirstPosX;
    pos.y = FirstPosY;

    // �v���C���[�摜�̓ǂݍ���
    LoadDivGraph("../asset/player/_idle.png", IdleAllNum, IdleXNum, IdleYNum, XSize, YSize, mIdle);
    LoadDivGraph("../asset/player/_run.png", RunAllNum, RunXNum, RunYNum, XSize, YSize, mRun);
    LoadDivGraph("../asset/player/_jump.png", JumpAllNum, JumpXNum, JumpYNum, XSize, YSize, mJump);
    LoadDivGraph("../asset/player/_throw.png", ThrowAllNum, ThrowXNum, ThrowYNum, XSize, YSize, mThrow);


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

    // �����A�j���[�V�������I�������t���O���~�낷
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

void Player::AnimationUpdate(float _deltaTime)
{
    IdleAnimation(_deltaTime);
    RunAnimation(_deltaTime);
    ThrowAnimation(_deltaTime);
    JumpAnimation(_deltaTime);
    AnimationControl();
}

void Player::AnimationControl()
{
    if (mThrowAnimationFlag)
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
