#include "Result.h"
#include "DxLib.h"
#include "../Scene/Title.h"

Result::Result(bool clearflag)
    : SceneBase()
{
    // リザルトシーン画像の読み込み
    if (clearflag)
    {
        sceneImage = LoadGraph("../asset/scene/_clearbg.png");
        gameclearImg = LoadGraph("../asset/scene/gameclear.png");
    }
    if (!clearflag)
    {
        sceneImage = LoadGraph("../asset/scene/gameoverbg.jpg");
        gameoverImg = LoadGraph("../asset/scene/gameover.png");
        continueImg = LoadGraph("../asset/scene/continue.png");
    }
}

Result::~Result()
{
    // リザルトシーン画像の後始末
    DeleteGraph(sceneImage);
    sceneImage = -1;
    gameoverImg = -1;
    continueImg = -1;
}

/// <summary>
/// リザルトシーンの更新処理
/// </summary>
/// <param name="_deltaTime">1フレームの経過時間</param>
/// <returns>現在のシーンのポインタ</returns>
SceneBase* Result::Update(float _deltaTime)
{
    // シーン遷移条件(スペースキーを押すと遷移（仮）)
    if (CheckHitKey(KEY_INPUT_A))
    {
        // 条件を満たしていたらリザルトシーンを生成してそのポインタを返す
        return new Title();
    }
    // リザルトシーンのポインタを返す
    return this;
}

/// <summary>
/// リザルトシーンの描画処理
/// </summary>
void Result::Draw()
{
    DrawGraph(0, 0, sceneImage, true);
    DrawGraph(100, 200, gameoverImg, true);
    DrawGraph(300, 350, gameclearImg, true);
    DrawRotaGraph(900, 700,0.8f,0, continueImg, true);
}
