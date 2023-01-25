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
const int YSize = 64;

//待機アニメーション
const int IdleAllNum = 2;
const int IdleXNum = 2;
const int IdleYNum = 1;
const int IdleXSize = 47 / IdleXNum;
const int IdleYSize = 50;

//走りアニメーション
const int RunAllNum = 4;
const int RunXNum = 4;
const int RunYNum = 1;
const int RunXSize = 150 / RunXNum;
const int RunYSize = 82;

//ジャンプアニメーション
const int JumpAllNum = 3;
const int JumpXNum = 3;
const int JumpYNum = 1;
const int JumpXSize = 150 / JumpXNum;
const int JumpYSize = 106;

//投げるアニメーション
const int ThrowAllNum = 6;
const int ThrowXNum = 6;
const int ThrowYNum = 1;
const int ThrowXSize = 150 / ThrowXNum;
const int ThrowYSize = 53;

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

    // 待機アニメーション設定
    void IdleAnimation(float _deltaTime);

    // 走りアニメーション設定
    void RunAnimation(float _deltaTime);

    // 投げアニメーション設定
    void ThrowAnimation(float _deltaTime);
    void SetThrowAnimationFlag(bool Status) { mThrowAnimationFlag = Status; }

    //ジャンプアニメーション設定
    void JumpAnimation(float _deltaTime);

    // アニメーション制御
    void AnimationUpdate(float _deltaTime);

    //描画制御
    void AnimationControl();

    void MapColEnter()override;
private:
    float playerVy;
    bool onGround;
    int jumpButtonCount;

    bool input;

    // アニメーション
    int mAnimation;

    //待機アニメーション関連
    int mIdle[IdleAllNum];
    int mIdleAnimation;
    float mIdleAnimCoolTime;

    //走りアニメ―ション関連
    int mRun[RunAllNum];
    int mRunAnimation;
    float mRunAnimCoolTime;

    //ジャンプアニメ―ション関連
    int mJump[JumpAllNum];
    int mJumpAnimation;
    float mJumpAnimCoolTime;
    bool jumpFlag;

    //投げアニメーション関連
    int mThrow[ThrowAllNum];
    int mThrowAnimation;
    float mThrowAnimCoolTime;
    bool mThrowAnimationFlag;

};