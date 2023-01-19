#include "Title.h"
#include "Play.h"

/// <summary>
/// コンストラクタ
/// </summary>
Title::Title()
    : SceneBase()
    , fadein(0)
    , bgPos(VGet(0, -1300, 0))
    , bgScrollSpeed(100.0f)
{
    // タイトル画像の読み込み
    sceneImage = LoadGraph("asset/scene/title.png");
    bg = nullptr;
}

/// <summary>
/// デストラクタ
/// </summary>
Title::~Title()
{
    // タイトル画像の後始末
    DeleteGraph(sceneImage);
    sceneImage = -1;
}

/// <summary>
/// タイトルの更新処理
/// </summary>
/// <param name="_deltaTime">1フレームの経過時間</param>
/// <returns>現在のシーンのポインタ</returns>
SceneBase* Title::Update(float _deltaTime)
{
    // 不透明でなければ
    if (fadein <= 255)
    {
        // 徐々に透明にしていく
        fadein++;
    }
    else
    {
        bgPos.x += bgScrollSpeed * _deltaTime;
        bgPos.y = 1300;

        // エンターが押されたら
        if (CheckHitKey(KEY_INPUT_RETURN))
        {
            // プレイシーンを生成してポインタを返す
            return new Play();
        }
    }

    // タイトルシーンのポインタを返す
    return this;
}

/// <summary>
/// タイトルの描画
/// </summary>
void Title::Draw()
{
    // 背景スクロール描画

    // フェードイン
    SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, fadein);

    // 画像描画
    DrawRotaGraph(960, 400, 1.5, 0, sceneImage, 1, 0);

    // 以降の画像モードを標準に設定
    SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, fadein);
}
