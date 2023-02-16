#pragma once

// ゲーム内アクター・当たり判定の種類別タグ
enum class ObjTag : unsigned char
{
    Player,
    Bullet,
    BulletDummy,
    Enemy,
    Map,
    Flag,
};

//------------------------------------------------------------------------------------
// @brief ループ制御用。上記タグの全要素を記述しておくこと.
//------------------------------------------------------------------------------------
constexpr static ObjTag ObjTagAll[] =
{
    ObjTag::Player,
    ObjTag::Bullet,
    ObjTag::BulletDummy,
    ObjTag::Enemy,
    ObjTag::Map,
    ObjTag::Flag,
};