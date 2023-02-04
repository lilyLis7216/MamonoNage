#pragma once

#include "DxLib.h"

class KeyMgr final
{
public:

    static void Initialize();                              // ゲームオブジェクトマネージャの初期化処理

    static void GetPush_KeyP();
    static int  KeyStatusP();

    static void GetPush_KeyI();
    static int  KeyStatusI();

    static void GetPush_KeyD();
    static int  KeyStatusD();

    static void GetPush_KeyA();
    static int  KeyStatusA();

    static int mastarkey[256];
    static bool tmppushP;
    static bool nowpushP;
    static bool tmppushI;
    static bool nowpushI;
    static bool tmppushD;
    static bool nowpushD;
    static bool tmppushA;
    static bool nowpushA;

private:
    KeyMgr();                                   // シングルトン
    ~KeyMgr();                                  // ゲームオブジェクトマネージャデストラクタ
    static KeyMgr* mpInstance;                  // マネージャの実体（アプリ内に唯一存在)
};