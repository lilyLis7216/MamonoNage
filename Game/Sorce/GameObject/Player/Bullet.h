#pragma once

#include "../GameObj.h"

class Bullet : public GameObj
{
public:
    Bullet(class Player* player);
    ~Bullet();

    void SetBulletPos(VECTOR plyPos) { if (!alive)pos = plyPos; }        ///�v���C���[�̒��S��e�̏����ʒu�ɑ��
    void SetBulletDir(bool plyDir) { rightDir = plyDir; }     ///�v���C���[�̌�����e�����ɑ��

    void BulletAngleSet(double mAngle);                          //�e�̊p�x���_�~�[���玝���Ă���
    void BulletMove();                                          //�e�̓���

    void Update(float deltaTime)override;                       //�X�V
    void Draw(int offSetX, int offSetY)override;                                        //�`��

    void SetonGround(bool isStand) { onGround = isStand; }      //���n���Ă��邩
    bool GetonGround() { return onGround; }                     //���n���Ă��邩�������Ă���

    void OnCollisionEnter(GameObj* other);

    VECTOR& GetPosition() { return pos; }                              //�e�̈ʒu�������Ă���

    void MapColEnter()override;
private:
    int     mRotation;                       //��]�p
    float   mMovePower;                      //�e�̔��˂̗�
    VECTOR  mBulletPower;                    //�e�̕���
    double  mBulletVX;                      //�e��X�����̗�
    double  mBulletVY;                      //�e��Y�����̗�
    int     mBulletNumber;                  //�e��

    VECTOR bulletPos;
    bool onGround;

};