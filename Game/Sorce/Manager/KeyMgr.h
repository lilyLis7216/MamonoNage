#pragma once

#include "DxLib.h"

class KeyMgr final
{
public:

    static void Initialize();                              // �Q�[���I�u�W�F�N�g�}�l�[�W���̏���������
    static void GetPush_KeyP();
    static int  KeyStatusP();

    static void GetPush_KeyI();
    static int  KeyStatusI();
    static bool tmppushP;
    static bool nowpushP;
    static bool tmppushI;
    static bool nowpushI;
private:
    KeyMgr();                                   // �V���O���g��
    ~KeyMgr();                                  // �Q�[���I�u�W�F�N�g�}�l�[�W���f�X�g���N�^
    static KeyMgr* mpInstance;                  // �}�l�[�W���̎��́i�A�v�����ɗB�ꑶ��)
};