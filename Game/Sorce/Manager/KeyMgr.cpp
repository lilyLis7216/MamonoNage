#include "KeyMgr.h"

KeyMgr* KeyMgr::mpInstance = nullptr;

bool KeyMgr::nowpushC = FALSE;
bool KeyMgr::tmppushC = FALSE;
bool KeyMgr::nowpushZ = FALSE;
bool KeyMgr::tmppushZ = FALSE;
bool KeyMgr::nowpushD = FALSE;
bool KeyMgr::tmppushD = FALSE;
bool KeyMgr::nowpushA = FALSE;
bool KeyMgr::tmppushA = FALSE;
int KeyMgr::mastarkey[256] = { 0 };
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

void KeyMgr::GetPush_KeyZ()
{
    //
    if (CheckHitKey(KEY_INPUT_Z))
    {
        nowpushZ = TRUE;
    }
    else
    {
        nowpushZ = FALSE;
    }
}

int KeyMgr::KeyStatusZ()
{
    GetPush_KeyZ();

    int ret = 0;

    //�{�^���������ꂽ�u��
    if (tmppushZ == FALSE && nowpushZ == TRUE)
    {
        ret = 1;
    }

    //�{�^��������������Ă�����
    else if (tmppushZ == TRUE && nowpushZ == TRUE)
    {
        ret = 2;
    }

    //�{�^���𗣂����u��
    else if (tmppushZ == TRUE && nowpushZ == FALSE)
    {
        ret = 3;
    }
    //�{�^����������Ă��Ȃ�

    else {
        ret = 0;
    }
    tmppushZ = nowpushZ;
    return ret;
}

void KeyMgr::GetPush_KeyC()
{
    if (CheckHitKey(KEY_INPUT_C))
    {
        nowpushC = TRUE;
    }
    else
    {
        nowpushC = FALSE;
    }
}

int KeyMgr::KeyStatusC()
{
    GetPush_KeyC();

    int ret = 0;

    //�{�^���������ꂽ�u��
    if (tmppushC == FALSE && nowpushC == TRUE)
    {
        ret = 1;
    }

    //�{�^��������������Ă�����
    else if (tmppushC == TRUE && nowpushC == TRUE)
    {
        ret = 2;
    }

    //�{�^���𗣂����u��
    else if (tmppushC == TRUE && nowpushC == FALSE)
    {
        ret = 3;
    }
    //�{�^����������Ă��Ȃ�

    else {
        ret = 0;
    }
    tmppushC = nowpushC;
    return ret;
}



int KeyMgr::KeyStatusD()
{
    GetPush_KeyD();

    int tmp = 0;

    //�{�^���������ꂽ�u��
    if (tmppushD == FALSE && nowpushD == TRUE)
    {
        tmp = 1;
    }

    //�{�^��������������Ă�����
    else if (tmppushD == TRUE && nowpushD == TRUE)
    {
        tmp = 2;
    }

    //�{�^���𗣂����u��
    else if (tmppushD == TRUE && nowpushD == FALSE)
    {
        tmp = 3;
    }
    //�{�^����������Ă��Ȃ�

    else {
        tmp = 0;
    }
    tmppushD = nowpushD;
    return tmp;
}
void KeyMgr::GetPush_KeyD()
{
    if (CheckHitKey(KEY_INPUT_D))
    {
        nowpushD = TRUE;
    }
    else
    {
        nowpushD = FALSE;
    }
}
void KeyMgr::GetPush_KeyA()
{
    if (CheckHitKey(KEY_INPUT_A))
    {
        nowpushA = TRUE;
    }
    else
    {
        nowpushA = FALSE;
    }
}

int KeyMgr::KeyStatusA()
{
    GetPush_KeyA();

    int ret = 0;

    //�{�^���������ꂽ�u��
    if (tmppushA == FALSE && nowpushA == TRUE)
    {
        ret = 1;
    }

    //�{�^��������������Ă�����
    else if (tmppushA == TRUE && nowpushA == TRUE)
    {
        ret = 2;
    }

    //�{�^���𗣂����u��
    else if (tmppushA == TRUE && nowpushA == FALSE)
    {
        ret = 3;
    }
    //�{�^����������Ă��Ȃ�

    else {
        ret = 0;
    }
    tmppushA = nowpushA;
    return ret;
}



