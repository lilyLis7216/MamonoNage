#pragma once

#include "../GameObj.h"
#include"../../Manager/GameObjMgr.h"

//�v���C���[�̏����ʒu
const int FirstPosX = 400;
const int FirstPosY = 200;

//�ړ����x
const float RunSpeed = 250.0f;

//�W�����v�֘A
const float jumpPower = 12.0f;     // �W�����v�����x
const float gravity = 0.3f;    // �d��
const float maxFallSpeed = 10.0f;   // �ő嗎�����x


////�v���C���[�̃T�C�Y
const int XSize = 64;
const int YSize = 128;




class Player : public GameObj
{
public:
    Player();

    ~Player();

    void Update(float _deltaTime) override;

    void Draw(int offSetX, int offSetY) override;

    void Init();

    void Move(float _deltaTime);

    // �L�����̍��W
    VECTOR& GetPosition() { return pos; }

    float GetVy() const { return playerVy; }

    int GetDir() const { return rightDir; }
 



    // �A�j���[�V��������
    void AnimationUpdate(float _deltaTime);

    void MapColEnter()override;

private:
    float playerVy;
    bool onGround;
    int jumpButtonCount;

    int key[256] = { 0 };
    bool input;

    // �A�j���[�V����
    int mAnimation;
    struct Animation
    {
        Animation(const char* filename,const int numx,const int numy);
        void LoadAnim(Animation* anim);
        void AnimUpdate(Animation* anim, float deltaTime, bool loop = true);
        const char* fileName;
        int numX;
        int numY;
        int AllNum;
        int animHandle[50];
        int flame;
        float coolTime;
        bool isPlay;
        bool isLoop;
    };
    Animation* anim[5];
    enum AnimType
    {
        IDLE = 0,
        RUN,
        ATK,
        JUMP,
        DAMAGE,
    };

    bool jumpFlag;
};