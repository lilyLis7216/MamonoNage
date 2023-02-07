#pragma once
#include <array>

const int BulletTypeAllNumber=4;
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
    /// 弾タイプ分け
    /// </summary>
    static enum BulletType{
        goast,
        slime,
        bat,
        skeleton
    };
    static float GoastCoolTime;
    static std::array<int, 4> bullets;//弾の配列
    static BulletType current_type;//今プレイヤーが準備している弾の種類


    /// <summary>
   /// 残弾数の取得
   /// </summary>
   /// <returns>現在の残弾数</returns>
    static int GetBulletNum(BulletType type) { return bullets[type]; }

    /// <summary>
    /// 残弾の加算(ゴースト以外)
    /// </summary>
    static void AddBulletNum(BulletType type) { bullets[type]++; }
    
    /// <summary>
    /// 残弾の加算(ゴースト)
    /// </summary>
    static void AddGoastBulletNum(float _deltaTime);

    /// <summary>
    /// 残弾の減算
    /// </summary>
    static void SubBulletNum(BulletType type) { bullets[type]--; }

    //弾の切り替え
    static void SwitchType(BulletType type);
private:
};