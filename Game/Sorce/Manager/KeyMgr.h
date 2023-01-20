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
    static bool tmppushP;
    static bool nowpushP;
    static bool tmppushI;
    static bool nowpushI;
private:
    KeyMgr();                                   // シングルトン
    ~KeyMgr();                                  // ゲームオブジェクトマネージャデストラクタ
    static KeyMgr* mpInstance;                  // マネージャの実体（アプリ内に唯一存在)
};