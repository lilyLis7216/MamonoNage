#pragma once

#include "../GameObj.h"
#include"../../Manager/GameObjMgr.h"

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
const int YSize = 128;

//�ҋ@�A�j���[�V����
const int IdleAllNum = 2;
const int IdleXNum = 2;
const int IdleYNum = 1;
//����A�j���[�V����
const int RunAllNum = 4;
const int RunXNum = 4;
const int RunYNum = 1;
//�W�����v�A�j���[�V����
const int JumpAllNum = 3;
const int JumpXNum = 3;
const int JumpYNum = 1;
//������A�j���[�V����
const int ThrowAllNum = 6;
const int ThrowXNum = 6;
const int ThrowYNum = 1;
//��_���[�W�A�j���[�V����
const int DamageAllNum = 2;
const int DamageXNum = 2;
const int DamageYNum = 1;

/// <summary>
/// enemyAnimation
/// </summary>
//�G�l�~�[�̃A�j���[�V�����m�F�p
const int EnemyXSize = 64;
const int EnemyYSize = 64;

const int EnemyRunAllNum = 4;
const int EnemyRunXNum = 4;
const int EnemyRunYNum = 1;

const int EnemyAttackAllNum = 4;
const int EnemyAttackXNum = 4;
const int EnemyAttackYNum = 1;

const int EnemyDamageAllNum = 2;
const int EnemyDamageXNum = 2;
const int EnemyDamageYNum = 1;


class Player : public GameObj
{
public:
    Player();

    ~Player();

    void Update(float _deltaTime) override;

    void Draw(int offSetX, int offSetY) override;

    void Init();

    void Move(float _deltaTime);

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

    //��_���[�W�A�j���[�V�����ݒ�
    void DamageAnimation(float _deltaTime);

    // �G�l�~�[�A�j���[�V�����m�F�p
    void EnemyRunAnimation(float _deltaTime);
    void EnemyDamageAnimation(float _deltaTime);
    void EnemyAttackAnimation(float _deltaTime);


    // �A�j���[�V��������
    void AnimationUpdate(float _deltaTime);

    //�`�搧��
    void AnimationControl();

    void MapColEnter()override;
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

    //��_���[�W�A�j���[�V�����֘A
    int mDamage[DamageAllNum]={-1};
    int mDamageAnimation=0;
    float mDamageAnimCoolTime=1.0f;
    bool mDamageAnimationFlag=FALSE;

    //�G�l�~�[�m�F�p
    int mEnemyRun[EnemyRunAllNum]={-1};
    int mEnemyRunAnimation=0;

    //�G�l�~�[�A�^�b�N
    int mEnemyAttack[EnemyAttackAllNum] = { -1 };
    int mEnemyAttackAnimation = 0;

    //�G�l�~�[�_���[�W
    int mEnemyDamage[EnemyDamageAllNum] = { -1 };
    int mEnemyDamageAnimation = 0;
};