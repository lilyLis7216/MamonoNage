#pragma once

#include "../GameObj.h"

class BulletDummy : public GameObj
{
public:
    BulletDummy(class Player* player);
    ~BulletDummy();


    void SetBulletDummyPos(VECTOR plyPos) { if (!alive)pos = plyPos; }        ///プレイヤーの中心を弾の初期位置に代入

    bool GetBulletDummyDir() { return rightDir; }
    void SetBulletDummyDir(bool plyDir) { rightDir = plyDir; }     ///プレイヤーの向きを弾方向に代入

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