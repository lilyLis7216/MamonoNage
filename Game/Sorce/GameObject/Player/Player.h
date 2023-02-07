#pragma once

#include "../GameObj.h"
#include"../../Manager/GameObjMgr.h"

//プレイヤーの初期位置
const int FirstPosX = 400;
const int FirstPosY = 200;

//移動速度
const float RunSpeed = 250.0f;

//ジャンプ関連
const float jumpPower = 12.0f;     // ジャンプ初速度
const float gravity = 0.3f;    // 重力
const float maxFallSpeed = 10.0f;   // 最大落下速度


////プレイヤーのサイズ
const int XSize = 64;
const int YSize = 128;




class Player : public GameObj
{
public:
    Player();

    ~Player();

    void Update(float _deltaTime) override;

    void Draw(int offSetX, int offSetY) override;

    void Init();

    void Move(float _deltaTime);

    // キャラの座標
    VECTOR& GetPosition() { return pos; }

    float GetVy() const { return playerVy; }

    int GetDir() const { return rightDir; }
 



    // アニメーション制御
    void AnimationUpdate(float _deltaTime);

    void MapColEnter()override;

private:
    float playerVy;
    bool onGround;
    int jumpButtonCount;

    int key[256] = { 0 };
    bool input;

    // アニメーション
    int mAnimation;
    struct Animation
    {
        Animation(const char* filename,const int numx,const int numy);
        void LoadAnim(Animation* anim);
        void AnimUpdate(Animation* anim, float deltaTime, bool loop = true);
        const char* fileName;
        int numX;
        int numY;
        int AllNum;
        int animHandle[50];
        int flame;
        float coolTime;
        bool isPlay;
        bool isLoop;
    };
    Animation* anim[5];
    enum AnimType
    {
        IDLE = 0,
        RUN,
        ATK,
        JUMP,
        DAMAGE,
    };

    bool jumpFlag;
};