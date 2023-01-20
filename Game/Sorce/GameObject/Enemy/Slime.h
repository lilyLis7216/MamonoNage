#pragma once

#include "Monster.h"

/// <summary>
/// �X���C���N���X�iMonster�p���j
/// </summary>
class Slime final : public Monster
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Slime();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Slime();

    /// <summary>
    /// �X���C���̍X�V����
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    void Update(float _deltaTime) override;

    /// <summary>
    /// �X���C���̕`�揈��
    /// </summary>
    void Draw(int, int) override;

private:
    // ���
    int state;

    // ��Ԃ̗�
    enum State
    {
        IDLE = 0,  // �ҋ@
        TRACK,     // �ǐ�
        ATTACK,    // �U��
        DEAD,      // ���S
    };

    // �U�����
    int atkState;

    // �U����Ԃ̗�
    enum AtkState
    {
        NONE = 0,  // �U�����Ă��Ȃ�
        START,     // �U���J�n
        NOW,       // �U���Œ�
        FINISH,    // �U���I��
    };

    /// <summary>
    /// �X���C���̒ǐՏ���
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    void Track(float _deltaTime);

    /// <summary>
    /// �X���C���̍U������
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    void Attack(float _deltaTime);

    /// <summary>
    /// �����Ă��邩�̊m�F
    /// </summary>
    /// <returns>�����Ă�����true �����łȂ����false</returns>
    bool IsFind(float playerPosX);

    // ���m�ł���͈�
    const float findRange = 160.0f;

    // �ǐՑ��x
    const float trackSpeed = 10.0f;
};