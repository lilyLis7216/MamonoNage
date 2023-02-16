#pragma once
class Pad
{
};

#pragma once

#include "DxLib.h"


    /// <summary>
    /// �Q�[���p�b�h�N���X
    /// </summary>
class GamePad final
{
private:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    GamePad();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~GamePad();

    // �Q�[���p�b�h�N���X�̗B��̃C���X�^���X
    static GamePad* instance;

    // �p�b�h�̓��͏��
    static XINPUT_STATE inputState;

    // �{�^���̓��̓r�b�g
    static int buttonBit;

    // 
    static int buttonState[16];

    static bool canUse;

public:
    /// <summary>
    /// �C���X�^���X�̐���
    /// </summary>
    static void CreateInstance();

    /// <summary>
    /// �C���X�^���X�̍폜
    /// </summary>
    static void DeleteInstance();

    /// <summary>
    /// �Q�[���p�b�h�̍X�V
    /// </summary>
    static void Update();

    // �{�^���̗񋓌^�i�}�W�b�N�i���o�[���p�j
    enum ButtonNum
    {
        UP = 0,  // �f�W�^�������{�^����
        DOWN,    // �f�W�^�������{�^����
        LEFT,    // �f�W�^�������{�^����
        RIGHT,   // �f�W�^�������{�^���E
        START,   // START�{�^��
        BACK,    // BACK�{�^��
        LSTICK,  // ���X�e�B�b�N��������
        RSTICK,  // �E�X�e�B�b�N��������
        LB,      // LB�{�^��
        RB,      // RB�{�^��
        NONE1,   // ����U��Ȃ�
        NONE2,   // ����U��Ȃ�
        A,       // A�{�^��
        B,       // B�{�^��
        X,       // X�{�^��
        Y,       // Y�{�^��
    };

    /// <summary>
    /// �{�^���̓��͏�Ԃ̎擾
    /// </summary>
    /// <param name="buttonNumber">�擾�������{�^��</param>
    /// <returns>���͂���Ă�����true �����łȂ����false</returns>
    static bool GetInput(const int buttonNumber);

    /// <summary>
    /// �{�^���̏�Ԏ擾
    /// </summary>
    /// <param name="buttonNumber">�擾�������{�^��</param>
    /// <returns>0:������Ă��Ȃ� 1:�����ꂽ�u�� 2�`:�������ςȂ� -1:�������u��</returns>
    static int GetButtonState(const int buttonNumber);

    /// <summary>
    /// ���g���K�[�̎擾
    /// </summary>
    /// <returns></returns>
    static const unsigned char GetLeftTrigger() { return inputState.LeftTrigger; }

    /// <summary>
    /// �E�g���K�[�̎擾
    /// </summary>
    /// <returns></returns>
    static const unsigned char GetRightTrigger() { return inputState.RightTrigger; }

    /// <summary>
    /// ���X�e�B�b�N��X���W
    /// </summary>
    /// <returns></returns>
    static const short GetLeftStickX() { return inputState.ThumbLX; }

    /// <summary>
    /// ���X�e�B�b�N��Y���W
    /// </summary>
    /// <returns></returns>
    static const short GetLeftStickY() { return inputState.ThumbLY; }

    /// <summary>
    /// �E�X�e�B�b�N��X���W
    /// </summary>
    /// <returns></returns>
    static const short GetRightStickX() { return inputState.ThumbRX; }

    /// <summary>
    /// �E�X�e�B�b�N��Y���W
    /// </summary>
    /// <returns></returns>
    static const short GetRightStickY() { return inputState.ThumbRY; }

    static void Vibration();

    static void SetPadUse(bool set) { canUse = set; }
};

#define Button GamePad::ButtonNum