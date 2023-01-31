#include "Bat.h"

/// <summary>
/// コンストラクタ
/// </summary>
Bat::Bat()
{
}

/// <summary>
/// デストラクタ
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
/// コウモリの更新処理
/// </summary>
/// <param name="_deltaTime">1フレームの経過時間</param>
void Bat::Update(float _deltaTime)
{
}

/// <summary>
/// コウモリの描画処理
/// </summary>
void Bat::Draw(int offSetX, int offSetY)
{
    DrawRotaGraph((int)pos.x - offSetX, (int)pos.y - offSetY, 2, 0, handle, TRUE, rightDir);
}
