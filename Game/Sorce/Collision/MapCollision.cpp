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