#pragma once

#include "Monster.h"

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
    /// �R�E�����̍X�V����
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    void Update(float _deltaTime) override;

    /// <summary>
    /// �R�E�����̕`�揈��
    /// </summary>
    void Draw(int, int) override;

private:
};