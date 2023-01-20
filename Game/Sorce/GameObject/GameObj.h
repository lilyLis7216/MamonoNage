#pragma once

#include "ObjTag.h"
#include "DxLib.h"

/// <summary>
/// ゲームオブジェクトクラス
/// </summary>
class GameObj
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="setTag">オブジェクトに設定するタグ</param>
    GameObj(ObjTag setTag);

    /// <summary>
    /// 仮想デストラクタ
    /// </summary>
    virtual ~GameObj();

    /// <summary>
    /// ゲームオブジェクトの更新処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    virtual void Update(float _deltaTime) = 0;

    /// <summary>
    /// ゲームオブジェクトの描画処理
    /// </summary>
    /// <param name="offSetX"></param>
    /// <param name="offSetY"></param>
    virtual void Draw(int offSetX, int offSetY) {}

    ObjTag GetTag() const { return tag; }

    void SetPos(VECTOR set) { pos = set; }
    VECTOR GetPos() const { return pos; }

    void SetAlive(bool set) { alive = set; }
    bool GetAlive() const { return alive; }

protected:
    // タグ
    ObjTag tag;

    // 座標
    VECTOR pos;

    // 生死状態
    bool alive;

    // 右向きか
    bool rightDir;

    // 描画用ハンドル
    int handle;
};