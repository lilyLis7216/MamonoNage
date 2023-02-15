#pragma once

#include "../GameObj.h"
#include "../Player/Bullet.h"
#include "../../Manager/EffectMgr.h"
#include "../../Manager/KeyMgr.h"
#include "../../Manager/BulletMgr.h"
#include "../../Manager/GameObjMgr.h"
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
    Monster(BulletMgr::BulletType bulletType,VECTOR pos);

    /// <summary>
    /// ���z�f�X�g���N�^
    /// </summary>
    virtual ~Monster();

    //����
    void Move(float _deltaTime);
    //�����]��
    void DirReverse(VECTOR ret);
    // ����A�j���[�V�����ݒ�
    void MoveAnimation(float _deltaTime);
    //��_���[�W�A�j���[�V�����ݒ�
    void DamageAnimation(float _deltaTime);
    //�U���A�j���[�V�����ݒ�
    void AttackAnimation(float _deltaTime);
    //�A�j���[�V�����R���g���[��
    void AnimationControl();
    
    //�G�l�~�[�^�C�v�����
    int GetemyType() { return emyType; }
    
    //
    int GetHandle() { return handle; }
    


    //�����蔻��
    void OnCollisionEnter(GameObj* other);
    void MapColEnter()override;

protected:
    BulletMgr::BulletType emyType;

    //���W�֘A
    
    VECTOR tmpPos = VGet(0,0,0);

    // ���x
    float speed=0.0f;

    //�d�͊֘A
    float mEmyVy;
    bool onEmyGround;
    bool onFirstEmyGround=false;

    //�������[�V����
    int mMove[EnemyMoveAllNum] = { -1 };
    int mMoveAnimation = 0;
    float mMoveAnimCoolTime = 0.2f;
    

    //�U�����[�V����
    int mAttack[EnemyAttackAllNum] = { -1 };
    int mAttackAnimation = 0;
    float mAttackAnimCoolTime = 0.2f;
    bool mAttackAnimationFlag = FALSE;

    //��_���\�W���[�V����
    int mDamage[EnemyDamageAllNum] = { -1 };
    int mDamageAnimation = 0;
    float mDamageAnimCoolTime = 0.2f;
    float mDamageTime = 0.5f;
    bool mDamageAnimationFlag = FALSE;
    bool DirFlag = FALSE;
    // �̗�
    int hp=0;

};