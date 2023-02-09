#include "BulletMgr.h"

//�z��̒���������
std::array<int, 4> BulletMgr::bullets = { 1, 2, 3 ,4};
BulletMgr::BulletType BulletMgr::current_type = BulletMgr::goast;
float BulletMgr::GoastCoolTime = 2.0f;
int BulletMgr::handle = 0;
int BulletMgr::mGoast = 0;
int BulletMgr::mSlime = 0;
int BulletMgr::mBat= 0;
int BulletMgr::mSkeleton= 0;

BulletMgr::BulletMgr()
{
    //LoadDivGraph("../asset/bullet/goast.png", 1, 1, 1, 32, 32, mGoast, TRUE);
    //LoadDivGraph("../asset/bullet/slime.png", 1, 1, 1, 32, 32, mSlime, TRUE);
    //LoadDivGraph("../asset/bullet/bat.png", 1, 1, 1, 32, 32, mBat, TRUE);
    //LoadDivGraph("../asset/bullet/skeleton.png", 1, 1, 1, 32, 32, mSkeleton, TRUE);

    mGoast=LoadGraph("../asset/bullet/goast.png");
    mSlime=LoadGraph("../asset/bullet/slime.png");
    mBat=LoadGraph("../asset/bullet/bat.png");
    mSkeleton=LoadGraph("../asset/bullet/skeleton.png");
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
        //�e�؂�ւ��J�n���S�[�X�g�������ꍇ
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
        //�e�؂�ւ��J�n���X���C���������ꍇ
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
        //�e�؂�ւ��J�n���R�E�����������ꍇ
        else if (type == bat)
        {
            current_type = skeleton;
            if (bullets[skeleton] == 0)
            {
                current_type = goast;
            }
        }
        //�e�؂�ւ��J�n���X�P���g���������ꍇ
        else if (type == skeleton)
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
