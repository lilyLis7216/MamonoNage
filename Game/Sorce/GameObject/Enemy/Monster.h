#pragma once

#include "../GameObj.h"
#include"../../Manager/KeyMgr.h"
#include"../../Manager/BulletMgr.h"
//�T�C�Y
const int EnemyXSize = 64;
const int EnemyYSize = 64;

//�A�j���[�V�����̋��ʗv�f(��_���[�W��XNum���Q)
const int EnemyXNum = 4;
const int EnemyYNum = 1;


//�ړ��A�j���[�V����
const int EnemyMoveAllNum = 4;
//�U���A�j���[�V�����֘A
const int EnemyAttackAllNum = 4;
//��_���[�W�A�j���[�V����
const int EnemyDamageAllNum = 2;
const int EnemyDamageXNum = 2;
/// <summary>
/// �����X�^�[�N���X�iGameObj�p���j
/// </summary>
class Monster : public GameObj
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Monster();

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="pos">�������W</param>
    Monster(VECTOR pos);

    /// <summary>
    /// ���z�f�X�g���N�^
    /// </summary>
    virtual ~Monster();

    // ����A�j���[�V�����ݒ�
    void MoveAnimation(float _deltaTime);
    //��_���[�W�A�j���[�V�����ݒ�
    void DamageAnimation(float _deltaTime);
    //�U���A�j���[�V�����ݒ�
    void AttackAnimation(float _deltaTime);
    //�A�j���[�V�����R���g���[��
    void AnimationControl();

    //�����蔻��
    void OnCollisionEnter(GameObj* other);

protected:
    // ���x
    float speed;

    //�������[�V����
    int mMove[EnemyMoveAllNum] = { -1 };
    int mMoveAnimation = 0;
    float mMoveAnimCoolTime = 0.2f;
    bool mDamageAnimationFlag = FALSE;

    //�U�����[�V����
    int mAttack[EnemyAttackAllNum] = { -1 };
    int mAttackAnimation = 0;
    float mAttackAnimCoolTime = 0.2f;
    bool mAttackAnimationFlag = FALSE;

    //��_���\�W���[�V����
    int mDamage[EnemyDamageAllNum] = { -1 };
    int mDamageAnimation = 0;
    float mDamageAnimCoolTime = 0.2f;

    // �̗�
    int hp;

};