#include "Play.h"

/// <summary>
/// コンストラクタ
/// </summary>
Play::Play()
{
}

/// <summary>
/// デストラクタ
/// </summary>
Play::~Play()
{
}

/// <summary>
/// プレイシーンの更新処理
/// </summary>
/// <param name="_deltaTime">1フレームの経過時間</param>
/// <returns>現在のシーンのポインタ</returns>
SceneBase* Play::Update(float _deltaTime)
{
    return this;
}

/// <summary>
/// プレイシーンの描画処理
/// </summary>
void Play::Draw()
{
}
