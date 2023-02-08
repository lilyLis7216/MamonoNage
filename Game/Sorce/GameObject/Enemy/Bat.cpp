#include "Bat.h"
#include"../../Manager/KeyMgr.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Bat::Bat()
{
}

Bat::Bat(VECTOR pos)
    : Monster(pos)
{
    pos = VGet(0, 0, 0);
    speed = 200.0f;
    LoadDivGraph("../asset/enemy/bat/Bat_move.png", EnemyMoveAllNum, EnemyXNum, EnemyYNum, EnemyXSize, EnemyYSize, mMove);
    LoadDivGraph("../asset/enemy/bat/Bat_attack.png", EnemyAttackAllNum, EnemyXNum, EnemyYNum, EnemyXSize, EnemyYSize, mAttack);
    LoadDivGraph("../asset/enemy/bat/Bat_damage.png", EnemyDamageAllNum, EnemyDamageXNum, EnemyYNum, EnemyXSize, EnemyYSize, mDamage);
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
Bat::~Bat()
{
}

/// <summary>
/// �R�E�����̍X�V����
/// </summary>
/// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
void Bat::Update(float _deltaTime)
{
    MoveAnimation(_deltaTime);
    DamageAnimation(_deltaTime);
    AttackAnimation(_deltaTime);
    AnimationControl();
}

/// <summary>
/// �R�E�����̕`�揈��
/// </summary>
void Bat::Draw(int offSetX, int offSetY)
{
    if (ShakeFlag)
    {
        DrawRotaGraph((int)pos.x - offSetX + ShakeMgr::GetShakePosX(), (int)pos.y - offSetY + ShakeMgr::GetShakePosY(), 1, 0, handle, TRUE, rightDir);
    }
    else
        DrawRotaGraph((int)pos.x - offSetX, (int)pos.y - offSetY, 1, 0, handle, TRUE, rightDir);
}
