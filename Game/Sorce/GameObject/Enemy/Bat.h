#pragma once

#include "Monster.h"


//�啂̃T�C�Y
const int XSize = 64;
const int YSize = 64;

//�A�j���[�V�����̋��ʗv�f(��_���[�W��XNum���Q)
const int XNum = 4;
const int YNum = 1;

//�ړ��A�j���[�V����
const int MoveAllNum = 4;
//�U���A�j���[�V�����֘A
const int AttackAllNum = 4;
//��_���[�W�A�j���[�V����
const int DamageAllNum = 2;
const int DamageXNum = 2;


/// <summary>
/// �R�E�����N���X�iMonster�p���j
/// </summary>
class Bat final : public Monster
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Bat();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Bat();

    /// <summary>
   /// �����ʒu���
   /// </summary>
   /// <param name="Pos"></csv���珉���ʒu�����������Ă���>
    void Init(VECTOR Pos);
    
    /// <summary>
    /// �R�E�����̍X�V����
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    void Update(float _deltaTime) override;

    /// <summary>
    /// �R�E�����̕`�揈��
    /// </summary>
    void Draw(int, int) override;

private:

    //�������[�V����
    int mMove[MoveAllNum] = { -1 };
    int mMoveAnimation = 0;
    float mMoveAnimCoolTime = 2.0f;

    //�U�����[�V����
    int mAttack[AttackAllNum] = { -1 };
    int mAttackAnimation = 0;
    float mAttackAnimCoolTime = 2.0f;

    //��_���\�W���[�V����
    int mDamage[DamageAllNum] = { -1 };
    int mDamageAnimation = 0;
    float mDamageAnimCoolTime = 2.0f;
};