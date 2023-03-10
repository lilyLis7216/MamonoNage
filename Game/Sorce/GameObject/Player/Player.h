#pragma once

#include "../GameObj.h"
#include"../../Manager/GameObjMgr.h"

//プレイヤーの初期位置
const int FirstPosX = 1000;
const int FirstPosY = 1460;

//プレイヤーの初期位置
//const int FirstPosX = 1000;
//const int FirstPosY = 360;

//移動速度
const float RunSpeed = 250.0f;

//ジャンプ関連
const float jumpPower = 12.0f;     // ジャンプ初速度
//const float gravity = 0.3f;    // 重力
//const float maxFallSpeed = 10.0f;   // 最大落下速度


////プレイヤーのサイズ
const int XSize = 64;
const int YSize = 128;

//待機アニメーション
const int IdleAllNum = 2;
const int IdleXNum = 2;
const int IdleYNum = 1;
//走りアニメーション
const int RunAllNum = 4;
const int RunXNum = 4;
const int RunYNum = 1;
//ジャンプアニメーション
const int JumpAllNum = 3;
const int JumpXNum = 3;
const int JumpYNum = 1;
//投げ準備アニメーション
const int PrepaAllNum = 2;
const int PrepaXNum = 2;
const int PrepaYNum = 1;
//投げるアニメーション
const int ThrowAllNum = 3;
const int ThrowXNum = 3;
const int ThrowYNum = 1;
//被ダメージアニメーション
const int DamageAllNum = 2;
const int DamageXNum = 2;
const int DamageYNum = 1;


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

    bool GetClearFlag() { return clearFlag; }
    // 待機アニメーション設定
    void IdleAnimation(float _deltaTime);

    // 走りアニメーション設定
    void RunAnimation(float _deltaTime);

    // 投げ準備アニメーション設定
    void ThrowPrepaAnimation(float _deltaTime);
    void SetThrowPrepaAnimationFlag(bool Status) { mPrepaAnimationFlag = Status; }
    // 投げアニメーション設定
    void ThrowAnimation(float _deltaTime);
    void SetThrowAnimationFlag(bool Status) { mThrowAnimationFlag = Status; }

    //ジャンプアニメーション設定
    void JumpAnimation(float _deltaTime);

    //被ダメージアニメーション設定
    void DamageAnimation(float _deltaTime);

    // アニメーション制御
    void AnimationUpdate(float _deltaTime);

    void deathplayer();

    //描画制御
    void AnimationControl();
    
    //当たり判定
    void OnCollisionEnter(GameObj* other);
    void MapColEnter()override;

    //プレイシーンを終わらせる
    bool GetPlySceneEndFlag()  {return PlySceneEndFlag;}

private:
    float playerVy;
    int jumpButtonCount;

    int key[256];
    bool input;

    bool PlySceneEndFlag=FALSE;
    bool clearFlag=FALSE;

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

    //投げ準備アニメーション関連
    int mPrepa[PrepaAllNum];
    int mPrepaAnimation;
    float mPrepaAnimCoolTime;
    bool mPrepaAnimationFlag=FALSE;

    //投げアニメーション関連
    int mThrow[ThrowAllNum];
    int mThrowAnimation;
    float mThrowAnimCoolTime;
    bool mThrowAnimationFlag;

    //被ダメージアニメーション関連
    int mDamage[DamageAllNum] = { -1 };
    int mDamageAnimation = 0;
    float mDamageAnimCoolTime = 1.0f;
    bool mDamageAnimationFlag = FALSE;
    float mDamageTime = 0.8f;
};