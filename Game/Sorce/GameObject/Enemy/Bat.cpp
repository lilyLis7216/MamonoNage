#include "Bat.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Bat::Bat()
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Bat::~Bat()
{
}

void Bat::Init(VECTOR Pos)
{
    pos = Pos;
    LoadDivGraph("../asset/enemy/bat/move.jpg", MoveAllNum, XNum, YNum, XSize, YSize, mMove);
    LoadDivGraph("../asset/enemy/bat/attack.jpg", MoveAllNum, XNum, YNum, XSize, YSize, mMove);
    LoadDivGraph("../asset/enemy/bat/damage.jpg", MoveAllNum, DamageXNum, YNum, XSize, YSize, mMove);

}
/// <summary>
/// �R�E�����̍X�V����
/// </summary>
/// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
void Bat::Update(float _deltaTime)
{
}

/// <summary>
/// �R�E�����̕`�揈��
/// </summary>
void Bat::Draw(int offSetX, int offSetY)
{
    DrawRotaGraph((int)pos.x - offSetX, (int)pos.y - offSetY, 2, 0, handle, TRUE, rightDir);
}
