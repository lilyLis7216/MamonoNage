#include "EffectMgr.h"

EffectMgr* EffectMgr::mpInstance = nullptr;

int EffectMgr::Ax=0;
int EffectMgr::Ay=0;
int EffectMgr::AXNum=10;
int EffectMgr::AYNum=1;
int EffectMgr::AXSize=120;
int EffectMgr::AYSize=120;
int EffectMgr::AHandle = 0;
float AAnimationTime=0.0f;
int EffectMgr::AEffect = 0;
int EffectMgr::AEffectAnimation[10];
bool EffectFlag = FALSE;

void EffectMgr::EffectA(float _deltaTime,int x, int y)
{
    Ax = x;
    Ay = y;
    LoadDivGraph("../asset/effect/EffectA.png", AXNum * AYNum, AXNum, AYNum, AXSize, AYSize, AEffectAnimation, TRUE);

    AAnimationTime -= _deltaTime;
    EffectFlag = TRUE;
    if (AAnimationTime < 0)
    {
        AEffect++;
        AAnimationTime = 0.0f;
    }
    AHandle = AEffectAnimation[AEffect];
}

EffectMgr::EffectMgr()
{
    mpInstance = nullptr;
}

EffectMgr::~EffectMgr()
{
}

void EffectMgr::CreateInstance()
{
    if (!mpInstance)
    {
        mpInstance = new EffectMgr;
    }
    
}

void EffectMgr::DeleteInstance()
{
}

void EffectMgr::ADraw()
{  /* if(EffectFlag)*/
    DrawRotaGraph(Ax, Ay, 10, 0, AHandle, TRUE);
}


