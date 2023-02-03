#include "Bat.h"
#include"../../Manager/KeyMgr.h"

/// <summary>
/// コンストラクタ
/// </summary>
Bat::Bat()
{
}

Bat::Bat(VECTOR pos)
    : Monster(pos)
{
    pos = VGet(0, 0, 0);
    speed = 200.0f;
    LoadDivGraph("../asset/enemy/bat/_move.png", EnemyMoveAllNum, EnemyXNum, EnemyYNum, EnemyXSize, EnemyYSize, mMove);
    LoadDivGraph("../asset/enemy/bat/_attack.png", EnemyAttackAllNum, EnemyXNum, EnemyYNum, EnemyXSize, EnemyYSize, mAttack);
    LoadDivGraph("../asset/enemy/bat/_damage.png", EnemyDamageAllNum, EnemyDamageXNum, EnemyYNum, EnemyXSize, EnemyYSize, mDamage);
}
/// <summary>
/// デストラクタ
/// </summary>
Bat::~Bat()
{
}

/// <summary>
/// コウモリの更新処理
/// </summary>
/// <param name="_deltaTime">1フレームの経過時間</param>
void Bat::Update(float _deltaTime)
{
    MoveAnimation(_deltaTime);
    DamageAnimation(_deltaTime);
    AttackAnimation(_deltaTime);
    AnimationControl();
}

/// <summary>
/// コウモリの描画処理
/// </summary>
void Bat::Draw(int offSetX, int offSetY)
{
    DrawRotaGraph((int)pos.x - offSetX, (int)pos.y - offSetY, 1, 0, handle, TRUE, rightDir);
}
