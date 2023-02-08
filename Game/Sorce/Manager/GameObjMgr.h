#pragma once

#include <vector>
#include <unordered_map>

#include "../GameObject/GameObj.h"

using namespace std;

class GameObjMgr final
{
public:
    /// <summary>
    /// インスタンスの生成
    /// </summary>
    static void CreateInstance();

    /// <summary>
    /// インスタンスの削除
    /// </summary>
    static void DeleteInstance();

    /// <summary>
    /// ゲームオブジェクト登録
    /// </summary>
    /// <param name="newObj">登録するオブジェクトのポインタ</param>
    static void Entry(GameObj* newObj);

    /// <summary>
    /// ゲームオブジェクト削除
    /// </summary>
    /// <param name="releaseObj">削除するオブジェクトのポインタ</param>
    static void Release(GameObj* relObj);

    /// <summary>
    /// ゲームオブジェクト全削除
    /// </summary>
    static void ReleaseAllObj();

    /// <summary>
    /// 全オブジェクトの更新処理
    /// </summary>
    /// <param name="_deltaTime">1フレームの経過時間</param>
    static void Update(float _deltaTime);

    /// <summary>
    /// 全オブジェクトの描画処理
    /// </summary>
    /// <param name="offSetX"></param>
    /// <param name="offSetY"></param>
    static void Draw(int offSetX, int offSetY);

    /// <summary>
    /// オブジェクトタグ種の最初のGameObjを返す
    /// </summary>
    /// <param name="tag">タグ</param>
    /// <returns>オブジェクトのポインタ</returns>
    static GameObj* GetFirstGameObj(ObjTag tag);


    static void ObjCollision();
private:
    /// <summary>
    /// コンストラクタ（シングルトン）
    /// </summary>
    GameObjMgr();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameObjMgr();

    // マネージャのインスタンス（アプリ内に唯一存在）
    static GameObjMgr* instance;

    // 一時待機オブジェクト
    vector<GameObj*> pendingObjects;

    // objects[タグ（種類）][オブジェクト個数]
    unordered_map<ObjTag, vector<GameObj*>> objects;
};