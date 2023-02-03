#include "Map.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Map::Map()
{
    LoadDivGraph("../asset/mapArufa/Block.png", (200 / 40) * (80 / 40), 200 / 40, 80/40, 40, 40, chipGraphicHandle);
    FILE* fp;

    // fopen_s�֐���map.csv��ǂݎ��`���ŊJ��
    fopen_s(&fp, "../asset/mapArufa/MaouMapBlock.csv", "r");

    // fp����̏ꍇ��
    if (fp == NULL)
    {
        // �f�o�b�O���~
        DebugBreak();
    }

    // memset�֐��Ń�������buf���Z�b�g���Asizeof���Z�q�ŗv�f�������߂�
    memset(buf, 0, sizeof(buf));

    while (1)
    {
        while (1)
        {
            // fgetc�֐���fp���當����ǂ��characterPack�Ɋi�[
            characterPack = fgetc(fp);

            // EOF�����o������
            if (characterPack == EOF)
            {
                // �t���O�𗧂Ă�
                eofFlag = true;

                // ���[�v�𔲂���
                break;
            }

            // ��؂肩���s�łȂ����
            if (characterPack != ',' && characterPack != '\n')
            {
                // strcat_s�֐���buf�ɘA�����Aconst char�Ɍ^�ϊ�
                strcat_s(buf, (const char*)&characterPack);
            }
            else
            {
                // atoi�֐���buf��int�^�ɒ����āAnum�ɑ��
                num = atoi(buf);

                // num�Ԗڂ̃`�b�v�摜�̃n���h�����擾
                map[columnNum][rawNum].graphicHandle = chipGraphicHandle[num];

                // buf�����Z�b�g
                memset(buf, 0, sizeof(buf));

                // ���[�v�𔲂���
                break;
            }
        }

        // 1�}�b�v���ɂȂ�����
        if (eofFlag)
        {
            // ���[�v�𔲂���
            break;
        }

        // ��؂�����o������
        if (characterPack == ',')
        {
            // ��̐��𑝂₷
            columnNum++;
        }

        // ���s��������
        if (characterPack == '\n')
        {
            // �s�̐��𑝂₷
            rawNum++;

            // ��̐���0�ɖ߂�
            columnNum = 0;
        }
    }
    fclose(fp);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Map::~Map()
{
}

/// <summary>
/// �}�b�v�̕`��
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
