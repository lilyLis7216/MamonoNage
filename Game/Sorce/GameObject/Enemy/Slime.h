#pragma once

#include "Monster.h"
#include"../../Manager/GameObjMgr.h"

/// <summary>
/// スライムクラス（Monster継承）
/// </summary>
class Slime final : public Monster
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Slime();

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="pos">初期座標</param>
    Slime(VECTOR pos);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Slime();

    /// <summary>
    /// スライムの更新処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    void Update(float _deltaTime) override;

    /// <summary>
    /// スライムの描画処理
    /// </summary>
    void Draw(int offSetX, int offSetY) override;

private:
    // 状態
    int state;

    // 状態の列挙
    enum State
    {
        IDLE = 0,  // 待機
        TRACK,     // 追跡
        ATTACK,    // 攻撃
        DEAD,      // 死亡
    };

    // 攻撃状態
    int atkState;

    // 攻撃状態の列挙
    enum AtkState
    {
        NONE = 0,  // 攻撃していない
        START,     // 攻撃開始
        NOW,       // 攻撃最中
        FINISH,    // 攻撃終了
    };

    /// <summary>
    /// スライムの追跡処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    void Track(float _deltaTime);

    /// <summary>
    /// スライムの攻撃処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    void Attack(float _deltaTime);

    /// <summary>
    /// 見つけているかの確認
    /// </summary>
    /// <returns>見つけていたらtrue そうでなければfalse</returns>
    bool IsFind(float playerPosX);

    // 検知できる範囲
    const float findRange = 160.0f;

    // 追跡速度
    const float trackSpeed = 10.0f;
};