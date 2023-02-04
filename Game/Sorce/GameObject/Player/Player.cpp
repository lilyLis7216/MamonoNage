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
    anim[IDLE] = new Animation("../asset/player/_idle.png", 2, 1);
    anim[RUN] = new Animation("../asset/player/_run.png", 4, 1);
    anim[ATK] = new Animation("../asset/player/_jump.png", 3, 1);
    anim[JUMP] = new Animation("../asset/player/_throw.png", 6, 1);
    anim[DAMAGE] = new Animation("../asset/player/_damage.png", 2, 1);
}

void Player::Move(float _deltaTime)
{
    handle = anim[IDLE]->animHandle[anim[IDLE]->flame];
    if (CheckHitKey(KEY_INPUT_RIGHT))
    {
        if (onGround)
        {
            handle = anim[RUN]->animHandle[anim[RUN]->flame];
        }
        rightDir = false;
        pos.x += RunSpeed * _deltaTime;
    }
    else if (CheckHitKey(KEY_INPUT_LEFT))
    {
        if (onGround)
        {
            handle = anim[RUN]->animHandle[anim[RUN]->flame];
        }
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
        else if (key[KEY_INPUT_J] > 1||key[KEY_INPUT_J]==-1)
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
    if (CheckHitKey(KEY_INPUT_P))
    {
    }
}

void Player::MapColEnter()
{
    VECTOR ret = CalcPushBack(collision, MapCollision::GetMapCol(),playerVy);
    pos = VAdd(pos, ret);
    onGround = collision->OnGround();
    ColUpdate();
}

Player::Animation::Animation(const char* filename, const int numx, const int numy)
    :fileName(filename)
    ,numX(numx)
    ,numY(numy)
    ,AllNum(numx*numy)
    ,flame(0)
    ,coolTime(0)
{
    animHandle[AllNum];
    LoadAnim(this);
}

void Player::Animation::LoadAnim(Animation* anim)
{
    LoadDivGraph(anim->fileName, anim->AllNum, anim->numX, anim->numY,
        XSize,YSize, anim->animHandle, TRUE);
}

void Player::Animation::AnimUpdate(Animation*anim,float deltaTime,bool loop)
{
    anim->coolTime -= deltaTime;
    if (anim->coolTime <= 0.0f)
    {
        if (anim->flame >= anim->AllNum)
        {
            if (loop)
            {
                anim->flame = 0;
            }
            else
            {
                isPlay = false;
            }
        }
        else
        {
            isPlay = true;
            anim->flame++;
        }
        anim->coolTime = 0.2f;
        anim->flame %= anim->AllNum;
    }
}

void Player::AnimationUpdate(float _deltaTime)
{
    anim[IDLE]->AnimUpdate(anim[IDLE], _deltaTime);
    anim[RUN]->AnimUpdate(anim[RUN], _deltaTime);

    anim[ATK]->AnimUpdate(anim[ATK], _deltaTime,false);
    anim[JUMP]->AnimUpdate(anim[JUMP], _deltaTime,false);
    anim[DAMAGE]->AnimUpdate(anim[DAMAGE], _deltaTime,false);

}


