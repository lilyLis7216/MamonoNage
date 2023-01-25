#pragma once
#include "DxLib.h"
#include"../GameObject/GameObj.h"

//当たり判定の幅
const int BOX_WIDTH = 40;

//当たり判定の高さ
const int BOX_HEIGHT = 40;

//当たり判定の横の数
const int BOX_NUM_X = 162;

//当たり判定の縦の数
const int BOX_NUM_Y = 54;

class MapCollision
{
public:
    /// <summary>
    /// インスタンスの生成
    /// </summary>
    static void CreateInstance();

    /// <summary>
    /// インスタンスの削除
    /// </summary>
    static void DeleteInstance();


    bool HitBlockType(int num, int num2, int blockType);

    static MapCollision* GetMapCol() { return mapcol; }
private:
    MapCollision();
    ~MapCollision();

    struct collLayer
    {
        int boxHandle;
    };

    collLayer coll[BOX_NUM_X][BOX_NUM_Y];

    // 当たり判定の種類
    int collBoxHandle[5];

    // 文字を格納する変数
    int marker;

    // 横方向のタイルナンバー
    int rawNum;

    // 縦方向のタイルナンバー
    int columnNum;

    // 当たり判定の番号
    int num;

    // 文字列変数
    char buf[10];

    // eof検出フラグ
    bool eofFlag;

    static MapCollision* mapcol;
};

