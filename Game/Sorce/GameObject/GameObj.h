#pragma once

#include "ObjTag.h"
#include "DxLib.h"
#include"../Collision/Collision.h"
#include"../ShakeMgr.h"

/// <summary>
/// �Q�[���I�u�W�F�N�g�N���X
/// </summary>
class GameObj
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="setTag">�I�u�W�F�N�g�ɐݒ肷��^�O</param>
    GameObj(ObjTag setTag);

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="setTag">�I�u�W�F�N�g�ɐݒ肷��^�O
    /// <param name="pos">�������W</param>
    GameObj(ObjTag setTag,VECTOR pos);

    /// <summary>
    /// ���z�f�X�g���N�^
    /// </summary>
    virtual ~GameObj();

    /// <summary>
    /// �Q�[���I�u�W�F�N�g�̍X�V����
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    virtual void Update(float _deltaTime) = 0;

    /// <summary>
    /// �Q�[���I�u�W�F�N�g�̕`�揈��
    /// </summary>
    /// <param name="offSetX"></param>
    /// <param name="offSetY"></param>
    virtual void Draw(int offSetX, int offSetY) {}

    ObjTag GetTag() const { return tag; }

    void SetPos(VECTOR set) { pos = set; }
    VECTOR GetPos() const { return pos; }

    void SetAlive(bool set) { alive = set; }
    bool GetAlive() const { return alive; }

    virtual void  OnCollisionEnter(GameObj* other) {}              // ���̃I�u�W�F�N�g�ƂԂ������Ƃ��̃��A�N�V�����i����΁j
    virtual void  MapColEnter() {}              // �}�b�v�ƂԂ������Ƃ��̃��A�N�V����

protected:
    void ColUpdate();                           // �����蔻��ʒu�̍X�V

    // �^�O
    ObjTag tag;

    // ���W
    VECTOR pos;

    // �������
    bool alive;

    // �E������
    bool rightDir;

    // �`��p�n���h��
    int handle;

    //�_���[�W�V�F�C�N�t���O
    bool ShakeFlag;

    class Collision* collision = nullptr;
};