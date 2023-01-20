#pragma once

#include "DxLib.h"

/// <summary>
/// �x�N�g�����m�̉��Z
/// </summary>
/// <param name="lhs">1�ڂ̃x�N�g��</param>
/// <param name="rhs">2�ڂ̃x�N�g��</param>
/// <returns>���Z��̃x�N�g��</returns>
VECTOR operator+(const VECTOR& lhs, const VECTOR& rhs);

/// <summary>
/// �x�N�g�����m�̌��Z
/// </summary>
/// <param name="lhs">1�ڂ̃x�N�g��</param>
/// <param name="rhs">2�ڂ̃x�N�g��</param>
/// <returns>���Z��̃x�N�g��</returns>
VECTOR operator-(const VECTOR& lhs, const VECTOR& rhs);

/// <summary>
/// �x�N�g���̃X�J���{�i���萔�j
/// </summary>
/// <param name="s">�萔</param>
/// <param name="rhs">�x�N�g��</param>
/// <returns>��Z��̃x�N�g��</returns>
VECTOR operator*(const float s, const VECTOR& rhs);

/// <summary>
/// �x�N�g���̃X�J���{�i�E�萔�j
/// </summary>
/// <param name="lhs">�x�N�g��</param>
/// <param name="s">�萔</param>
/// <returns>��Z��̃x�N�g��</returns>
VECTOR operator*(const VECTOR& lhs, const float s);

/// <summary>
/// �x�N�g���̉��Z���
/// </summary>
/// <param name="lhs">��������̃x�N�g��</param>
/// <param name="rhs">�������x�N�g��</param>
/// <returns>���Z��̃x�N�g��</returns>
VECTOR operator+=(VECTOR& lhs, const VECTOR& rhs);

/// <summary>
/// �x�N�g���̌��Z���
/// </summary>
/// <param name="lhs">��������x�N�g��</param>
/// <param name="rhs">�������x�N�g��</param>
/// <returns>���Z��̃x�N�g��</returns>
VECTOR operator-=(VECTOR& lhs, const VECTOR& rhs);

/// <summary>
/// �x�N�g���̏�Z���
/// </summary>
/// <param name="lhs">�x�N�g��</param>
/// <param name="s">�萔</param>
/// <returns>��Z��̃x�N�g��</returns>
VECTOR operator*=(VECTOR& lhs, const float s);