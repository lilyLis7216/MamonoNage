#pragma once

#include "../GameObj.h"

//�v���C���[�̏����ʒu
const int FirstPosX = 400;
const int FirstPosY = 200;

//�ړ����x
const float RunSpeed = 250.0f;

//�W�����v�֘A
const float jumpPower = 12.0f;     // �W�����v�����x
const float gravity = 0.3f;    // �d��
const float maxFallSpeed = 10.0f;   // �ő嗎�����x


////�v���C���[�̃T�C�Y
const int XSize = 64;
const int YSize = 64;

//�ҋ@�A�j���[�V����
const int IdleAllNum = 2;
const int IdleXNum = 2;
const int IdleYNum = 1;
const int IdleXSize = 47 / IdleXNum;
const int IdleYSize = 50;

//����A�j���[�V����
const int RunAllNum = 4;
const int RunXNum = 4;
const int RunYNum = 1;
const int RunXSize = 150 / RunXNum;
const int RunYSize = 82;

//�W�����v�A�j���[�V����
const int JumpAllNum = 3;
const int JumpXNum = 3;
const int JumpYNum = 1;
const int JumpXSize = 150 / JumpXNum;
const int JumpYSize = 106;

//������A�j���[�V����
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

    void SetonGround(bool set) { onGround = set; }

    // �L�����̍��W
    VECTOR& GetPosition() { return pos; }

    float GetVy() const { return playerVy; }

    int GetDir() const { return rightDir; }

    // �ҋ@�A�j���[�V�����ݒ�
    void IdleAnimation(float _deltaTime);

    // ����A�j���[�V�����ݒ�
    void RunAnimation(float _deltaTime);

    // �����A�j���[�V�����ݒ�
    void ThrowAnimation(float _deltaTime);
    void SetThrowAnimationFlag(bool Status) { mThrowAnimationFlag = Status; }

    //�W�����v�A�j���[�V�����ݒ�
    void JumpAnimation(float _deltaTime);

    // �A�j���[�V��������
    void AnimationUpdate(float _deltaTime);

    //�`�搧��
    void AnimationControl();

private:
    float playerVy;
    bool onGround;
    int jumpButtonCount;

    bool input;

    // �A�j���[�V����
    int mAnimation;

    //�ҋ@�A�j���[�V�����֘A
    int mIdle[IdleAllNum];
    int mIdleAnimation;
    float mIdleAnimCoolTime;

    //����A�j���\�V�����֘A
    int mRun[RunAllNum];
    int mRunAnimation;
    float mRunAnimCoolTime;

    //�W�����v�A�j���\�V�����֘A
    int mJump[JumpAllNum];
    int mJumpAnimation;
    float mJumpAnimCoolTime;
    bool jumpFlag;

    //�����A�j���[�V�����֘A
    int mThrow[ThrowAllNum];
    int mThrowAnimation;
    float mThrowAnimCoolTime;
    bool mThrowAnimationFlag;
};