#include "Skeleton.h"
#include"../../Manager/KeyMgr.h"

Skeleton::Skeleton()
{
}

Skeleton::Skeleton(VECTOR pos)
    : Monster(pos)
{
    pos = VGet(0, 0, 0);
    speed = 200.0f;
    LoadDivGraph("../asset/enemy/skeleton/_move.png", EnemyMoveAllNum, EnemyXNum, EnemyYNum, EnemyXSize, EnemyYSize, mMove);
    LoadDivGraph("../asset/enemy/skeleton/_attack.png", EnemyMoveAllNum, EnemyXNum, EnemyYNum, EnemyXSize, EnemyYSize, mAttack);
    LoadDivGraph("../asset/enemy/skeleton/_damage.png", EnemyDamageAllNum, EnemyDamageXNum, EnemyYNum, EnemyXSize, EnemyYSize, mDamage);
}

Skeleton::~Skeleton()
{
    DeleteGraph(handle);
    handle = -1;
}

void Skeleton::Update(float _deltaTime)
{
    MoveAnimation(_deltaTime);
    DamageAnimation(_deltaTime);
    AttackAnimation(_deltaTime);
    AnimationControl();
}

void Skeleton::Draw(int offSetX, int offSetY)
{
    if (ShakeFlag)
    {
        DrawRotaGraph((int)pos.x - offSetX+ShakeMgr::GetShakePosX(), (int)pos.y - offSetY+ShakeMgr::GetShakePosY(), 1, 0, handle, TRUE, rightDir);
    }
    else
    DrawRotaGraph((int)pos.x - offSetX, (int)pos.y - offSetY, 1, 0, handle, TRUE, rightDir);
}
