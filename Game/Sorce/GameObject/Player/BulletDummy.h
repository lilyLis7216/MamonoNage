#pragma once

#include "../GameObj.h"

class BulletDummy : public GameObj
{
public:
    BulletDummy(class Player* player);
    ~BulletDummy();


    void SetBulletDummyPos(VECTOR plyPos) { if (!alive)pos = plyPos; }        ///�v���C���[�̒��S��e�̏����ʒu�ɑ��

    bool GetBulletDummyDir() { return rightDir; }
    void SetBulletDummyDir(bool plyDir) { rightDir = plyDir; }     ///�v���C���[�̌�����e�����ɑ��

    double GetRadian() { return mAngle; }
    void  AddRadian(float _deltaTime);
    void  AddAngleChange();

    void Update(float deltaTime)override;
    void Draw(int offSetX, int offSetY)override;

private:
    double mAngle;
    double AddAngle;
    float mRotation;
};