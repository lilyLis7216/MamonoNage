#pragma once

const int ScreenBeside = 1920;
const int ScreenVertical = 1080;
const int ColorDepth = 16;

/// <summary>
/// シーンベースクラス
/// </summary>
class SceneBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    SceneBase();

    /// <summary>
    /// 仮想デストラクタ
    /// </summary>
    virtual ~SceneBase();

    /// <summary>
    /// シーンの更新処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    /// <returns>現在のシーンのポインタ</returns>
    virtual SceneBase* Update(float _deltaTime) = 0;

    /// <summary>
    /// シーンの描画処理
    /// </summary>
    virtual void Draw() = 0;

protected:
    // シーンの画像
    int sceneImage;
};