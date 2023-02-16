#include "BulletMgr.h"

//配列の中を初期化
std::array<int, 4> BulletMgr::bullets = { 1, 0, 0 ,0};
BulletMgr::BulletType BulletMgr::current_type = BulletMgr::goast;
float BulletMgr::GoastCoolTime = 3.0f;
int BulletMgr::handle = 0;
int BulletMgr::mGoast = 0;
int BulletMgr::mSlime = 0;
int BulletMgr::mBat= 0;
int BulletMgr::mSkeleton= 0;

BulletMgr::BulletMgr()
{

    mGoast=LoadGraph("../asset/bullet/goast.png");
    mSlime=LoadGraph("../asset/bullet/slime.png");
    mBat=LoadGraph("../asset/bullet/bat.png");
    mSkeleton=LoadGraph("../asset/bullet/skeleton.png");

}

BulletMgr::~BulletMgr()
{

}

void BulletMgr::AddBulletNum(int mHandle)
{
    if (mHandle == mSlime)
    {
        bullets[slime]++;
    }
    if (mHandle == mBat)
    {
        bullets[bat]++;
    }
    if (mHandle == mSkeleton)
    {
        bullets[skeleton]++;
    }
}

void BulletMgr::AddGoastBulletNum(float _deltaTime)
{
    if (bullets[goast] == 0)
    {
        GoastCoolTime -= _deltaTime;
        if (GoastCoolTime < 0) 
        {
            bullets[goast]++;
            GoastCoolTime = 3.0f;
        }
    }
}

//void BulletMgr::GoastBullet()
//{
//}

void BulletMgr::SwitchType(BulletType type)
{
    {
        //弾切り替え開始時ゴーストだった場合
        if (type == goast)
        {
            current_type = slime;
            if (bullets[slime] == 0)
            {
                current_type = bat;
                if (bullets[bat] == 0)
                {
                    current_type = skeleton;
                    if (bullets[skeleton] == 0)
                    {
                        current_type = goast;
                    }
                }
            }
        }
        //弾切り替え開始時スライムだった場合
        else if (type == slime)
        {
            current_type = bat;
            if (bullets[bat] == 0)
            {
                current_type = skeleton;
                if (bullets[skeleton] == 0)
                {
                    current_type = goast;
                }
            }
        }
        //弾切り替え開始時コウモリだった場合
        else if (type == bat)
        {
            current_type = skeleton;
            if (bullets[skeleton] == 0)
            {
                current_type = goast;
            }
        }
        //弾切り替え開始時スケルトンだった場合
        else if (type == skeleton)
        {
            current_type = goast;
        }
    }
}


void BulletMgr::AutoSwitchType(BulletType type)
{
    {
        
        //弾切り替え開始時スライムだった場合
        if (type == slime && bullets[slime]==0)
        {
            current_type = bat;
            if (bullets[bat] == 0)
            {
                current_type = skeleton;
                if (bullets[skeleton] == 0)
                {
                    current_type = goast;
                }
            }
        }
        //弾切り替え開始時コウモリだった場合
        else if (type == bat && bullets[bat] == 0)
        {
            current_type = skeleton;
            if (bullets[skeleton] == 0)
            {
                current_type = goast;
            }
        }
        //弾切り替え開始時スケルトンだった場合
        else if (type == skeleton && bullets[skeleton] == 0)
        {
            current_type = goast;
        }
    }
}
void BulletMgr::Draw(VECTOR PlayerPos, bool RightDir, int offSetX, int offSetY)
{
   
    VECTOR ReadyBullet = PlayerPos;
    ReadyBullet.y -= 110;
    
    if (RightDir)
    {
        ReadyBullet.x += 48;
    }
    else
    {
        ReadyBullet.x -= 100;
    }


   if (current_type == skeleton)
    {
        handle = mSkeleton;
    }
    else if (current_type == bat)
    {
        handle = mBat;
    }
    else if(current_type == slime)
    {
        handle = mSlime;
    }
    else if(current_type==goast)
    {
        handle = mGoast;
    }
    else
    {

    }
    
    DrawExtendGraph((int)ReadyBullet.x - offSetX, (int)ReadyBullet.y - offSetY, (int)ReadyBullet.x - offSetX + 32 * 1.5, (int)ReadyBullet.y - offSetY + 32 * 1.5, handle, TRUE);
}
