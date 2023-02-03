#pragma once

#include "Monster.h"



/// <summary>
/// �X�P���g���N���X�iMonster�p���j
/// </summary>
class Skeleton final : public Monster
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Skeleton();
    Skeleton(VECTOR pos);

    /// <summary>
   /// �f�X�g���N�^
   /// </summary>
    ~Skeleton();

    /// <summary>
    /// �X�P���g���̃A�b�v�f�[�g
    /// </summary>
    /// <param name="_deltaTime"></param>
    void Update(float _deltaTime)override;

    // <summary>
    /// �X�P���g���̕`�揈��
    /// </summary>
    void Draw(int offSetX, int offSetY) override;

};

