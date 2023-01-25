#include "MapCollision.h"

MapCollision* MapCollision::mapcol = nullptr;

MapCollision::MapCollision()
    : marker(0)
    , rawNum(0)
    , columnNum(0)
    , num(0)
    , eofFlag(false)
{
    mapcol = nullptr;

    //当たり判定チェック用画像
    LoadDivGraph("../asset/mapArufa/collision_new_check.png", 5, 5, 1, BOX_WIDTH, BOX_HEIGHT, collBoxHandle);

    FILE* fp;

    //fopen_s関数でcsvファイルを読み取り形式で開く
    fopen_s(&fp, "../asset/mapArufa/Maoumap_collision.csv", "r");

    //fpが空の時は
    if (fp == NULL)
    {
        //デバッグ中止
        DebugBreak();
    }

    //memset関数でメモリにbufをセット、sizeof演算子で要素数を決める
    memset(buf, 0, sizeof(buf));

    while (!eofFlag)
    {
        while (!eofFlag)
        {
            //fpから文字を読んでmarkerに格納
            marker = fgetc(fp);

            //EOFを検出したらフラグを立てる
            if (marker == EOF)
            {
                eofFlag = true;
            }

            //区切り化改行でなければ
            if (marker != ',' && marker != '\n')
            {
                //bufに連結して、const char関数で書き換える
                strcat_s(buf, (const char*)&marker);
            }
            else
            {
                //bufをint型に直してnumに代入
                num = atoi(buf);

                //num番号のハンドルを取得
                coll[columnNum][rawNum].boxHandle = collBoxHandle[num];

                //memset関数でメモリにbufをセット、sizeof演算子で要素数を決める
                memset(buf, 0, sizeof(buf));

                //区切りか改行なのでループで抜ける
                break;
            }
        }

        if (marker == ',')
        {
            columnNum++;
        }

        if (marker == '\n')
        {
            //区切りは列を増やし、改行は行を増やして列を0にする
            rawNum++;
            columnNum = 0;
        }
    }

    //ファイルを閉じる
    fclose(fp);
}

MapCollision::~MapCollision()
{
}

void MapCollision::CreateInstance()
{
    if (!mapcol)
    {
        mapcol = new MapCollision();
    }
}

void MapCollision::DeleteInstance()
{
    if (mapcol)
    {
        delete mapcol;
        mapcol = nullptr;
    }
}

bool MapCollision::HitBlockType(int num,int num2, int blockType)
{
    if (coll[num][num2].boxHandle == collBoxHandle[blockType])
    {
        return true;
    }
    return false;
}