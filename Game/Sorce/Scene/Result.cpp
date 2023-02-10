#include "Result.h"
#include "DxLib.h"


Result::Result()
    : SceneBase()
{
    // リザルトシーン画像の読み込み
    sceneImage = LoadGraph("../asset/scene/Result.png");
}

Result::~Result()
{
    // リザルトシーン画像の後始末
    DeleteGraph(sceneImage);
    sceneImage = -1;
}

/// <summary>
/// リザルトシーンの更新処理
/// </summary>
/// <param name="_deltaTime">1フレームの経過時間</param>
/// <returns>現在のシーンのポインタ</returns>
SceneBase* Result::Update(float _deltaTime)
{
    // リザルトシーンのポインタを返す
    return this;
}

/// <summary>
/// リザルトシーンの描画処理
/// </summary>
void Result::Draw()
{
    DrawGraph(0, 0, sceneImage, true);
}
