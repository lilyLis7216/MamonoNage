#pragma once

/// <summary>
/// 弾管理クラス
/// </summary>
class BulletMgr final
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    BulletMgr();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~BulletMgr();

    /// <summary>
    /// 残弾数の取得
    /// </summary>
    /// <returns>現在の残弾数</returns>
    static int GetBulletNum() { return bulletNum; }

    /// <summary>
    /// 残弾の加算
    /// </summary>
    static void AddBulletNum() { bulletNum++; }

    /// <summary>
    /// 残弾の減算
    /// </summary>
    static void SubBulletNum() { bulletNum--; }

private:
    // 残弾数
    static int bulletNum;
};