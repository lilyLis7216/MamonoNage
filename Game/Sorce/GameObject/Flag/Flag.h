#pragma once
#include "../GameObj.h"
#include"../../Manager/GameObjMgr.h"

////ƒS[ƒ‹‚Ì‰ŠúˆÊ’u
//const int POSX = 1000;
//const int POSY = 360;

class Flag :
    public GameObj
{
public:
    Flag();
    ~Flag();

    void Update(float _deltaTime) override;

    void Draw(int offSetX, int offSetY) override;

    void OnCollisionEnter(GameObj* other);
};

