#include "Math.h"

/// <summary>
/// �x�N�g�����m�̉��Z
/// </summary>
/// <param name="lhs">1�ڂ̃x�N�g��</param>
/// <param name="rhs">2�ڂ̃x�N�g��</param>
/// <returns>���Z��̃x�N�g��</returns>
VECTOR operator+(const VECTOR& lhs, const VECTOR& rhs)
{
    VECTOR retVec;
    retVec.x = lhs.x + rhs.x;
    retVec.y = lhs.y + rhs.y;
    retVec.z = lhs.z + rhs.z;
    return retVec;
}

/// <summary>
/// �x�N�g�����m�̌��Z
/// </summary>
/// <param name="lhs">1�ڂ̃x�N�g��</param>
/// <param name="rhs">2�ڂ̃x�N�g��</param>
/// <returns>���Z��̃x�N�g��</returns>
VECTOR operator-(const VECTOR& lhs, const VECTOR& rhs)
{
    VECTOR retVec;
    retVec.x = lhs.x - rhs.x;
    retVec.y = lhs.y - rhs.y;
    retVec.z = lhs.z - rhs.z;
    return retVec;
}

/// <summary>
/// �x�N�g���̃X�J���{�i���萔�j
/// </summary>
/// <param name="s">�萔</param>
/// <param name="rhs">�x�N�g��</param>
/// <returns>��Z��̃x�N�g��</returns>
VECTOR operator*(const float s, const VECTOR& rhs)
{
    VECTOR retVec;
    retVec.x = s * rhs.x;
    retVec.y = s * rhs.y;
    retVec.z = s * rhs.z;
    return retVec;
}

/// <summary>
/// �x�N�g���̃X�J���{�i�E�萔�j
/// </summary>
/// <param name="lhs">�x�N�g��</param>
/// <param name="s">�萔</param>
/// <returns>��Z��̃x�N�g��</returns>
VECTOR operator*(const VECTOR& lhs, const float s)
{
    VECTOR retVec;
    retVec.x = lhs.x * s;
    retVec.y = lhs.y * s;
    retVec.z = lhs.z * s;
    return retVec;
}

/// <summary>
/// �x�N�g���̉��Z���
/// </summary>
/// <param name="lhs">��������̃x�N�g��</param>
/// <param name="rhs">�������x�N�g��</param>
/// <returns>���Z��̃x�N�g��</returns>
VECTOR operator+=(VECTOR& lhs, const VECTOR& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

/// <summary>
/// �x�N�g���̌��Z���
/// </summary>
/// <param name="lhs">��������x�N�g��</param>
/// <param name="rhs">�������x�N�g��</param>
/// <returns>���Z��̃x�N�g��</returns>
VECTOR operator-=(VECTOR& lhs, const VECTOR& rhs)
{
    lhs = lhs - rhs;
    return lhs;
}

/// <summary>
/// �x�N�g���̏�Z���
/// </summary>
/// <param name="lhs">�x�N�g��</param>
/// <param name="s">�萔</param>
/// <returns>��Z��̃x�N�g��</returns>
VECTOR operator*=(VECTOR& lhs, const float s)
{
    lhs = lhs * s;
    return lhs;
}