#pragma once

// マップセルの横幅
const int CELL_WIDTH = 40;

// マップセルの高さ
const int CELL_HEIGHT = 40;

// x方向のタイル数
const int CELL_NUM_X = 162;

// y方向のタイル数
const int CELL_NUM_Y = 54;

/// <summary>
/// マップクラス
/// </summary>
class Map final
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Map();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Map();

    /// <summary>
    /// マップの描画
    /// </summary>
    /// <param name="scrX"></param>
    /// <param name="scrY"></param>
    void Draw(int scrX, int scrY);

protected:

    struct mapLayer
    {
        int graphicHandle;
    };

    // 
    mapLayer map[CELL_NUM_X][CELL_NUM_Y] = { 0 };

    // 
    int chipGraphicHandle[(200 / 40) * (80 / 40)];

    // 
    int characterPack;

    // 横方向タイルナンバー
    int rawNum = 0;

    // 縦方向タイルナンバー
    int columnNum = 0;

    // タイルの番号
    int num = 0;

    // 文字列変数
    char buf[10];

    // eof検出フラグ
    bool eofFlag = false;
};