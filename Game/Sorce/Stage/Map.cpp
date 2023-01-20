#include "Map.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ
/// </summary>
Map::Map()
{
    LoadDivGraph("../asset/mapArufa/mapsozai.png", (200 / 40) * (40 / 40), 200 / 40, 40, 40, 40, chipGraphicHandle);
    FILE* fp;

    // fopen_s関数でmap.csvを読み取り形式で開く
    fopen_s(&fp, "../asset/mapArufa/Maoumap_map.csv", "r");

    // fpが空の場合は
    if (fp == NULL)
    {
        // デバッグ中止
        DebugBreak();
    }

    // memset関数でメモリにbufをセットし、sizeof演算子で要素数を決める
    memset(buf, 0, sizeof(buf));

    while (1)
    {
        while (1)
        {
            // fgetc関数でfpから文字を読んでcharacterPackに格納
            characterPack = fgetc(fp);

            // EOFを検出したら
            if (characterPack == EOF)
            {
                // フラグを立てて
                eofFlag = true;

                // ループを抜ける
                break;
            }

            // 区切りか改行でなければ
            if (characterPack != ',' && characterPack != '\n')
            {
                // strcat_s関数でbufに連結し、const charに型変換
                strcat_s(buf, (const char*)&characterPack);
            }
            else
            {
                // atoi関数でbufをint型に直して、numに代入
                num = atoi(buf);

                // num番目のチップ画像のハンドルを取得
                map[columnNum][rawNum].graphicHandle = chipGraphicHandle[num];

                // bufをリセット
                memset(buf, 0, sizeof(buf));

                // ループを抜ける
                break;
            }
        }

        // 1マップ文になったら
        if (eofFlag)
        {
            // ループを抜ける
            break;
        }

        // 区切りを検出したら
        if (characterPack == ',')
        {
            // 列の数を増やす
            columnNum++;
        }

        // 改行だったら
        if (characterPack == '\n')
        {
            // 行の数を増やす
            rawNum++;

            // 列の数を0に戻す
            columnNum = 0;
        }
    }
    fclose(fp);
}

/// <summary>
/// デストラクタ
/// </summary>
Map::~Map()
{
}

/// <summary>
/// マップの描画
/// </summary>
/// <param name="scrX"></param>
/// <param name="scrY"></param>
void Map::Draw(int scrX, int scrY)
{
    for (int i = 0; i < CELL_NUM_X; i++)
    {
        for (int j = 0; j < CELL_NUM_Y; j++)
        {
            DrawExtendGraph(i * CELL_WIDTH - scrX, j * CELL_HEIGHT - scrY,
                (i + 1) * CELL_WIDTH - scrX, (j + 1) * CELL_HEIGHT - scrY, map[i][j].graphicHandle, TRUE);
        }
    }
}
