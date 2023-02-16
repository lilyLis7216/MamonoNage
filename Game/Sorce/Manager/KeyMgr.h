#pragma once

#include "DxLib.h"

class KeyMgr final
{
public:

    static void Initialize();                              // ゲームオブジェクトマネージャの初期化処理

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
    KeyMgr();                                   // シングルトン
    ~KeyMgr();                                  // ゲームオブジェクトマネージャデストラクタ
    static KeyMgr* mpInstance;                  // マネージャの実体（アプリ内に唯一存在)
};