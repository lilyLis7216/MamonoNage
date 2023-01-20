#include "Collision.h"
#include "../GameObject/Player/Player.h"

Collision::Collision()
    : marker(0)
    , rawNum(0)
    , columnNum(0)
    , num(0)
    , eofFlag(false)
{
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

Collision::~Collision()
{
}

bool Collision::CollBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
    int objLX = (int)(objPos.x - XSize / 4);
    int objLY = (int)(objPos.y - YSize / 4);
    int objRX = (int)(objPos.x + XSize / 4);
    int objRY = (int)(objPos.y + YSize / 1.5f);

    //現在のタイル位置//
    int tileLX = objLX / BOX_WIDTH;
    int tileLY = objLY / BOX_HEIGHT;
    int tileRX = objRX / BOX_WIDTH;
    int tileRY = objRY / BOX_HEIGHT;

    for (int iy = tileLY; iy < tileRY + 1; iy++)
    {
        for (int jx = tileLX; jx < tileRX + 1; jx++)
        {
            //当たり判定BOXの頂点座標//
            int boxLX = jx * BOX_WIDTH;
            int boxLY = iy * BOX_HEIGHT;
            int boxRX = boxLX + BOX_WIDTH;
            int boxRY = boxLY + BOX_HEIGHT;

            //押し出し処理//
            int bx1 = boxLX - objRX;
            int bx2 = boxRX - objLX;
            int by1 = boxLY - objRY;
            int by2 = boxRY - objLY;

            int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
            int by = (abs(by1) < abs(by2)) ? by1 : by2;
            if (coll[jx][iy].boxHandle != collBoxHandle[0])
            {
                if (abs(bx) < abs(by))
                {
                    if (coll[jx - 1][iy].boxHandle == collBoxHandle[0] ||
                        coll[jx + 1][iy].boxHandle == collBoxHandle[0])
                    {
                        objPos.x += bx;
                    }
                }
                else
                {
                    if (coll[jx][iy - 1].boxHandle == collBoxHandle[0] ||
                        coll[jx][iy + 1].boxHandle == collBoxHandle[0])
                    {
                        objPos.y += by;
                        if (by <= 0)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
