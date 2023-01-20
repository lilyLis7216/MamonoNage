#pragma once

#include "../GameObj.h"

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
    /// ���z�f�X�g���N�^
    /// </summary>
    virtual ~Monster();

protected:
    // ���x
    float speed;

    // �ړ��A�j���[�V����
    int moveAnim[4] = { -1 };

    // �U���A�j���[�V����
    int atkAnim[4] = { -1 };

    // ��e�A�j���[�V����
    int damageAnim[2] = { -1 };

    // �̗�
    int hp;

};