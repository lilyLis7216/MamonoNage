#include "GameObj.h"

GameObj::GameObj(ObjTag setTag)
    : tag(setTag)
    , pos(VGet(0,0,0))
    , alive(true)
    , rightDir(true)
    , handle(-1)
{
}

GameObj::~GameObj()
{
    // ˆ—‚È‚µ
}
