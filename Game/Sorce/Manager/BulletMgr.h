#pragma once
#include <array>
#include"DxLib.h"
#include"../Collision/MapCollision.h"

const int BulletTypeAllNumber=4;
/// <summary>
/// �e�Ǘ��N���X
/// </summary>
class BulletMgr final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    BulletMgr();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~BulletMgr();

    /// <summary>
    /// �e�^�C�v����
    /// </summary>
    static enum BulletType{
        goast,
        slime,
        bat,
        skeleton
    };
    static float GoastCoolTime;
    static std::array<int, 4> bullets;//�e�̔z��
    static BulletType current_type;//���v���C���[���������Ă���e�̎��


    /// <summary>
   /// �c�e���̎擾
   /// </summary>
   /// <returns>���݂̎c�e��</returns>
    static int GetBulletNum(BulletType type) { return bullets[type]; }

    /// <summary>
    /// �c�e�̉��Z(�S�[�X�g�ȊO)
    /// </summary>
    static void AddBulletNum(BulletType type) { bullets[type]++; }
    
    /// <summary>
    /// �c�e�̉��Z(�S�[�X�g)
    /// </summary>
    static void AddGoastBulletNum(float _deltaTime);

    /// <summary>
    /// �c�e�̌��Z
    /// </summary>
    static void SubBulletNum(BulletType type) { bullets[type]--; }

    //�e�̐؂�ւ�
    static void SwitchType(BulletType type);

    static int GetHandle() { return handle; }

    static void Draw(VECTOR PlayerPos,bool RightDir, int offSetX, int offSetY);
private:
    static int mGoast;
    static int mSlime;
    static int mBat;
    static int mSkeleton;
    static int handle;
};