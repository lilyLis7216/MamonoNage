#include "Collision.h"
#include "../GameObject/Player/Player.h"

Collision::Collision()
    : marker(0)
    , rawNum(0)
    , columnNum(0)
    , num(0)
    , eofFlag(false)
{
    //�����蔻��`�F�b�N�p�摜
    LoadDivGraph("../asset/mapArufa/collision_new_check.png", 5, 5, 1, BOX_WIDTH, BOX_HEIGHT, collBoxHandle);

    FILE* fp;

    //fopen_s�֐���csv�t�@�C����ǂݎ��`���ŊJ��
    fopen_s(&fp, "../asset/mapArufa/Maoumap_collision.csv", "r");

    //fp����̎���
    if (fp == NULL)
    {
        //�f�o�b�O���~
        DebugBreak();
    }

    //memset�֐��Ń�������buf���Z�b�g�Asizeof���Z�q�ŗv�f�������߂�
    memset(buf, 0, sizeof(buf));

    while (!eofFlag)
    {
        while (!eofFlag)
        {
            //fp���當����ǂ��marker�Ɋi�[
            marker = fgetc(fp);

            //EOF�����o������t���O�𗧂Ă�
            if (marker == EOF)
            {
                eofFlag = true;
            }

            //��؂艻���s�łȂ����
            if (marker != ',' && marker != '\n')
            {
                //buf�ɘA�����āAconst char�֐��ŏ���������
                strcat_s(buf, (const char*)&marker);
            }
            else
            {
                //buf��int�^�ɒ�����num�ɑ��
                num = atoi(buf);

                //num�ԍ��̃n���h�����擾
                coll[columnNum][rawNum].boxHandle = collBoxHandle[num];

                //memset�֐��Ń�������buf���Z�b�g�Asizeof���Z�q�ŗv�f�������߂�
                memset(buf, 0, sizeof(buf));

                //��؂肩���s�Ȃ̂Ń��[�v�Ŕ�����
                break;
            }
        }

        if (marker == ',')
        {
            columnNum++;
        }

        if (marker == '\n')
        {
            //��؂�͗�𑝂₵�A���s�͍s�𑝂₵�ė��0�ɂ���
            rawNum++;
            columnNum = 0;
        }
    }

    //�t�@�C�������
    fclose(fp);
}

Collision::~Collision()
{
}

bool Collision::CollBox(VECTOR& objPos)
{
    //�I�u�W�F�N�gBOX�̒��_���W//
    int objLX = (int)(objPos.x - XSize / 4);
    int objLY = (int)(objPos.y - YSize / 4);
    int objRX = (int)(objPos.x + XSize / 4);
    int objRY = (int)(objPos.y + YSize / 1.5f);

    //���݂̃^�C���ʒu//
    int tileLX = objLX / BOX_WIDTH;
    int tileLY = objLY / BOX_HEIGHT;
    int tileRX = objRX / BOX_WIDTH;
    int tileRY = objRY / BOX_HEIGHT;

    for (int iy = tileLY; iy < tileRY + 1; iy++)
    {
        for (int jx = tileLX; jx < tileRX + 1; jx++)
        {
            //�����蔻��BOX�̒��_���W//
            int boxLX = jx * BOX_WIDTH;
            int boxLY = iy * BOX_HEIGHT;
            int boxRX = boxLX + BOX_WIDTH;
            int boxRY = boxLY + BOX_HEIGHT;

            //�����o������//
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
