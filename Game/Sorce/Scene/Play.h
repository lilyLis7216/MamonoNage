#pragma once

#include "SceneBase.h"

class Background;
class Map;
class Flag;
class Scroll;
class MapCollision;
//class SkeltonBlock;

class Player;
class BulletDummy;
class Bullet;
class BulletMgr;

class Play : public SceneBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Play();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Play();

    /// <summary>
    /// �v���C�V�[���̍X�V����
    /// </summary>
    /// <param name="_deltaTime">1�t���[���̌o�ߎ���</param>
    /// <returns>���݂̃V�[���̃|�C���^</returns>
    SceneBase* Update(float _deltaTime) override;

    /// <summary>
    /// �v���C�V�[���̕`�揈��
    /// </summary>
    void Draw() override;

    ///// <summary>
    ///// �L�������n�ʂɗ����Ă��邩�ǂ������ׂ�
    ///// </summary>
    //void isStand();


    /// <summary>
    /// �L�������o���b�g�𓊂���܂ł̗���
    /// </summary>
    void ShotFlow(float _deltaTime);

private:
    Background* bg;
    Map* map;
    Flag* flag;
    Scroll* scroll;
    MapCollision* mapcol=nullptr;
    // SkeltonBlock* block;

    Player* player;
    BulletDummy* dummy;
    Bullet* bullet;
    BulletMgr* bulletMgr;
};