#pragma once

/// <summary>
/// �e�Ǘ��N���X
/// </summary>
class BulletMgr final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    BulletMgr();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~BulletMgr();

    /// <summary>
    /// �c�e���̎擾
    /// </summary>
    /// <returns>���݂̎c�e��</returns>
    static int GetBulletNum() { return bulletNum; }

    /// <summary>
    /// �c�e�̉��Z
    /// </summary>
    static void AddBulletNum() { bulletNum++; }

    /// <summary>
    /// �c�e�̌��Z
    /// </summary>
    static void SubBulletNum() { bulletNum--; }

private:
    // �c�e��
    static int bulletNum;
};