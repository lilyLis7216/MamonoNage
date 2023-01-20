#include "Monster.h"

Monster::Monster()
    : GameObj(ObjTag::Enemy)
    , speed(0)
    , hp(0)
{
}

Monster::~Monster()
{
}
