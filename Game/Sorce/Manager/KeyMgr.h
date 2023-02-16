#pragma once

#include "DxLib.h"
#include "../Pad/Pad.h"
class KeyMgr final
{
public:

    static void Initialize();                              // �Q�[���I�u�W�F�N�g�}�l�[�W���̏���������

    static void GetPush_KeyZ();
    static int  KeyStatusZ();

    static void GetPush_KeyC();
    static int  KeyStatusC();

    static void GetPush_KeyD();
    static int  KeyStatusD();

    static void GetPush_KeyA();
    static int  KeyStatusA();

    static int mastarkey[256];
    static bool tmppushZ;
    static bool nowpushZ;
    static bool tmppushC;
    static bool nowpushC;
    static bool tmppushD;
    static bool nowpushD;
    static bool tmppushA;
    static bool nowpushA;

private:
    KeyMgr();                                   // �V���O���g��
    ~KeyMgr();                                  // �Q�[���I�u�W�F�N�g�}�l�[�W���f�X�g���N�^
    static KeyMgr* mpInstance;                  // �}�l�[�W���̎��́i�A�v�����ɗB�ꑶ��)
};