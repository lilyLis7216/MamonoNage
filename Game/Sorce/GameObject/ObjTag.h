#pragma once

// �Q�[�����A�N�^�[�E�����蔻��̎�ޕʃ^�O
enum class ObjTag : unsigned char
{
    Player,
    Bullet,
    BulletDummy,
    Enemy,
};

//------------------------------------------------------------------------------------
// @brief ���[�v����p�B��L�^�O�̑S�v�f���L�q���Ă�������.
//------------------------------------------------------------------------------------
constexpr static ObjTag ObjTagAll[] =
{
    ObjTag::Player,
    ObjTag::Bullet,
    ObjTag::BulletDummy,
    ObjTag::Enemy,
};