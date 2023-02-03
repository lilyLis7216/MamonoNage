#pragma once

#include "Monster.h"

/// <summary>
/// �S�[�����N���X�iMonster�p���j
/// </summary>
class Golem final : public Monster
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Golem();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Golem();

    // ����A�j���[�V�����ݒ�
    void MoveAnimation(float _deltaTime);
    //��_���[�W�A�j���[�V�����ݒ�
    void DamageAnimation(float _deltaTime);
    //�U���A�j���[�V�����ݒ�
    void AttackAnimation(float _deltaTime);
    //�A�j���[�V�����R���g���[��
    void AnimationControl();

    /// <summary>
    /// �S�[�����̍X�V����
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    void Update(float _deltaTime) override;

    /// <summary>
    /// �S�[�����̕`�揈��
    /// </summary>
    void Draw(int, int) override;

private:
};