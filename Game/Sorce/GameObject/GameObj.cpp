#include "GameObj.h"

GameObj::GameObj(ObjTag setTag)
    : tag(setTag)
    , pos(VGet(0,0,0))
    , alive(true)
    , rightDir(true)
    , handle(-1)
    ,ShakeFlag(FALSE)
{
}

GameObj::GameObj(ObjTag setTag,VECTOR pos)
    : tag(setTag)
    , pos(pos)
    , alive(true)
    , rightDir(true)
    , handle(-1)
    , ShakeFlag(FALSE)
{
}

GameObj::~GameObj()
{
    // ˆ—‚È‚µ
}

void GameObj::ColUpdate()
{
    if (collision)
    {
        collision->Move(pos);
    }
}