#include "Slime.h"

/// <summary>
/// コンストラクタ
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
/// コンストラクタ
/// </summary>
Slime::Slime(VECTOR pos)
    : Monster(BulletMgr::BulletType::slime,pos)
    , state(IDLE)
    , atkState(NONE)
{
    pos = VGet(0, 0, 0);
    speed = 200.0f;
    handle = LoadGraph("../asset/enemy/slime.png");
}

/// <summary>
/// デストラクタ
/// </summary>
Slime::~Slime()
{
    DeleteGraph(handle);
    handle = -1;
}

/// <summary>
/// スライムの更新処理
/// </summary>
/// <param name="_deltaTime">1フレームの経過時間</param>
void Slime::Update(float _deltaTime)
{
    // 生死状態の確認をする
    //CheckAlive();

    // 死んでいなければ
    if (state != DEAD)
    {
        // プレイヤーの座標を持ってくる
        GameObj* player =GameObjMgr::GetFirstGameObj(ObjTag::Player);

         bool find=IsFind(player->GetPos().x);

        // プレイヤーを見つけていたら
        if (find)
        {
            // 追跡状態なら
            if (state == TRACK)
            {
                Track(_deltaTime);
            }
            // 攻撃状態なら
            else if (state == ATTACK)
            {
                Attack(_deltaTime);
            }
        }
    }
}

/// <summary>
/// スライムの描画処理
/// </summary>
void Slime::Draw(int offSetX, int offSetY)
{
    DrawRotaGraph((int)pos.x-offSetX, (int)pos.y-offSetY, 2, 0, handle, TRUE, rightDir);
}

/// <summary>
/// スライムの追跡処理
/// </summary>
/// <param name="_deltaTime">1フレームの経過時間</param>
void Slime::Track(float _deltaTime)
{
    // プレイヤーのX座標から自身のX座標を引いた値を正規化して速度とデルタタイムをかける
}

/// <summary>
/// スライムの攻撃処理
/// </summary>
/// <param name="_deltaTime">1フレームの経過時間</param>
void Slime::Attack(float _deltaTime)
{
    // 攻撃の初動
    if (atkState == START)
    {

    }
    // 攻撃の最中
    else if (atkState == NOW)
    {

    }
    // 攻撃の終わり
    else if (atkState == FINISH)
    {

    }
}

/// <summary>
/// 見つけているかの確認
/// </summary>
/// <returns>見つけていたらtrue そうでなければfalse</returns>
bool Slime::IsFind(float playerPosX)
{
    // 右を向いている場合
    if (rightDir)
    {
        // 座標の差分が4マス（160px）より小さければ
        if (pos.x - playerPosX > -findRange)
        {
            // 見つけていると返す
            return true;
        }
    }
    // 左を向いている場合
    else
    {
        // 座標の差分が4マス（160px）より小さければ
        if (pos.x - playerPosX < findRange)
        {
            // 見つけていると返す
            return true;
        }
    }

    // 見つけていないと返す
    return false;
}
