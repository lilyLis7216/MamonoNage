#include "BulletMgr.h"

//配列の中を初期化
std::array<int, 4> BulletMgr::bullets = { 1, 2, 3 ,4};
BulletMgr::BulletType BulletMgr::current_type = BulletMgr::goast;
float BulletMgr::GoastCoolTime = 2.0f;

BulletMgr::BulletMgr()
{
}

BulletMgr::~BulletMgr()
{
}

void BulletMgr::AddGoastBulletNum(float _deltaTime)
{
    if (bullets[goast] == 0)
    {
        GoastCoolTime -= _deltaTime;
        if (GoastCoolTime < 0) 
        {
            bullets[goast]++;
            GoastCoolTime = 2.0f;
        }
    }
}

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
