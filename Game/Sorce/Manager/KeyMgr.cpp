#include "KeyMgr.h"

KeyMgr* KeyMgr::mpInstance = nullptr;

bool KeyMgr::nowpushI = FALSE;
bool KeyMgr::tmppushI = FALSE;
bool KeyMgr::nowpushP = FALSE;
bool KeyMgr::tmppushP = FALSE;


KeyMgr::KeyMgr()
{
    mpInstance = nullptr;
}

KeyMgr::~KeyMgr()
{
}

void KeyMgr::Initialize()
{
    if (!mpInstance)
    {
        mpInstance = new KeyMgr;
    }
}

void KeyMgr::GetPush_KeyP()
{
    if (CheckHitKey(KEY_INPUT_P))
    {
        nowpushP = TRUE;
    }
    else
    {
        nowpushP = FALSE;
    }
}

int KeyMgr::KeyStatusP()
{
    GetPush_KeyP();

    int ret = 0;

    //ボタンが押された瞬間
    if (tmppushP == FALSE && nowpushP == TRUE)
    {
        ret = 1;
    }

    //ボタンが長押しされている状態
    else if (tmppushP == TRUE && nowpushP == TRUE)
    {
        ret = 2;
    }

    //ボタンを離した瞬間
    else if (tmppushP == TRUE && nowpushP == FALSE)
    {
        ret = 3;
    }
    //ボタンが押されていない

    else {
        ret = 0;
    }
    tmppushP = nowpushP;
    return ret;
}

void KeyMgr::GetPush_KeyI()
{
    if (CheckHitKey(KEY_INPUT_I))
    {
        nowpushI = TRUE;
    }
    else
    {
        nowpushI = FALSE;
    }
}

int KeyMgr::KeyStatusI()
{
    GetPush_KeyI();

    int tmp = 0;

    //ボタンが押された瞬間
    if (tmppushI == FALSE && nowpushI == TRUE)
    {
        tmp = 1;
    }

    //ボタンが長押しされている状態
    else if (tmppushI == TRUE && nowpushI == TRUE)
    {
        tmp = 2;
    }

    //ボタンを離した瞬間
    else if (tmppushI == TRUE && nowpushI == FALSE)
    {
        tmp = 3;
    }
    //ボタンが押されていない

    else {
        tmp = 0;
    }
    tmppushI = nowpushI;
    return tmp;
}
