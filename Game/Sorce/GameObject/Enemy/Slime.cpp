#include "Slime.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Slime::Slime()
    : Monster()
    , state(IDLE)
    , atkState(NONE)
{
    pos = VGet(0, 0, 0);
    speed = 200.0f;
    handle = LoadGraph("../asset/enemy/slime.png");
}

/// <summary>
/// �R���X�g���N�^
/// </summary>
Slime::Slime(VECTOR pos)
    : Monster(pos)
    , state(IDLE)
    , atkState(NONE)
{
    pos = VGet(0, 0, 0);
    speed = 200.0f;
    handle = LoadGraph("../asset/enemy/slime.png");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Slime::~Slime()
{
    DeleteGraph(handle);
    handle = -1;
}

/// <summary>
/// �X���C���̍X�V����
/// </summary>
/// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
void Slime::Update(float _deltaTime)
{
    // ������Ԃ̊m�F������
    //CheckAlive();

    // ����ł��Ȃ����
    if (state != DEAD)
    {
        // �v���C���[�̍��W�������Ă���
        GameObj* player =GameObjMgr::GetFirstGameObj(ObjTag::Player);

         bool find=IsFind(player->GetPos().x);

        // �v���C���[�������Ă�����
        if (find)
        {
            // �ǐՏ�ԂȂ�
            if (state == TRACK)
            {
                Track(_deltaTime);
            }
            // �U����ԂȂ�
            else if (state == ATTACK)
            {
                Attack(_deltaTime);
            }
        }
    }
}

/// <summary>
/// �X���C���̕`�揈��
/// </summary>
void Slime::Draw(int offSetX, int offSetY)
{
    DrawRotaGraph((int)pos.x-offSetX, (int)pos.y-offSetY, 2, 0, handle, TRUE, rightDir);
}

/// <summary>
/// �X���C���̒ǐՏ���
/// </summary>
/// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
void Slime::Track(float _deltaTime)
{
    // �v���C���[��X���W���玩�g��X���W���������l�𐳋K�����đ��x�ƃf���^�^�C����������
}

/// <summary>
/// �X���C���̍U������
/// </summary>
/// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
void Slime::Attack(float _deltaTime)
{
    // �U���̏���
    if (atkState == START)
    {

    }
    // �U���̍Œ�
    else if (atkState == NOW)
    {

    }
    // �U���̏I���
    else if (atkState == FINISH)
    {

    }
}

/// <summary>
/// �����Ă��邩�̊m�F
/// </summary>
/// <returns>�����Ă�����true �����łȂ����false</returns>
bool Slime::IsFind(float playerPosX)
{
    // �E�������Ă���ꍇ
    if (rightDir)
    {
        // ���W�̍�����4�}�X�i160px�j��菬�������
        if (pos.x - playerPosX > -findRange)
        {
            // �����Ă���ƕԂ�
            return true;
        }
    }
    // ���������Ă���ꍇ
    else
    {
        // ���W�̍�����4�}�X�i160px�j��菬�������
        if (pos.x - playerPosX < findRange)
        {
            // �����Ă���ƕԂ�
            return true;
        }
    }

    // �����Ă��Ȃ��ƕԂ�
    return false;
}
