#include "Math.h"

/// <summary>
/// ベクトル同士の加算
/// </summary>
/// <param name="lhs">1つ目のベクトル</param>
/// <param name="rhs">2つ目のベクトル</param>
/// <returns>加算後のベクトル</returns>
VECTOR operator+(const VECTOR& lhs, const VECTOR& rhs)
{
    VECTOR retVec;
    retVec.x = lhs.x + rhs.x;
    retVec.y = lhs.y + rhs.y;
    retVec.z = lhs.z + rhs.z;
    return retVec;
}

/// <summary>
/// ベクトル同士の減算
/// </summary>
/// <param name="lhs">1つ目のベクトル</param>
/// <param name="rhs">2つ目のベクトル</param>
/// <returns>減算後のベクトル</returns>
VECTOR operator-(const VECTOR& lhs, const VECTOR& rhs)
{
    VECTOR retVec;
    retVec.x = lhs.x - rhs.x;
    retVec.y = lhs.y - rhs.y;
    retVec.z = lhs.z - rhs.z;
    return retVec;
}

/// <summary>
/// ベクトルのスカラ倍（左定数）
/// </summary>
/// <param name="s">定数</param>
/// <param name="rhs">ベクトル</param>
/// <returns>乗算後のベクトル</returns>
VECTOR operator*(const float s, const VECTOR& rhs)
{
    VECTOR retVec;
    retVec.x = s * rhs.x;
    retVec.y = s * rhs.y;
    retVec.z = s * rhs.z;
    return retVec;
}

/// <summary>
/// ベクトルのスカラ倍（右定数）
/// </summary>
/// <param name="lhs">ベクトル</param>
/// <param name="s">定数</param>
/// <returns>乗算後のベクトル</returns>
VECTOR operator*(const VECTOR& lhs, const float s)
{
    VECTOR retVec;
    retVec.x = lhs.x * s;
    retVec.y = lhs.y * s;
    retVec.z = lhs.z * s;
    return retVec;
}

/// <summary>
/// ベクトルの加算代入
/// </summary>
/// <param name="lhs">代入されるのベクトル</param>
/// <param name="rhs">代入するベクトル</param>
/// <returns>加算後のベクトル</returns>
VECTOR operator+=(VECTOR& lhs, const VECTOR& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

/// <summary>
/// ベクトルの減算代入
/// </summary>
/// <param name="lhs">代入されるベクトル</param>
/// <param name="rhs">代入するベクトル</param>
/// <returns>減算後のベクトル</returns>
VECTOR operator-=(VECTOR& lhs, const VECTOR& rhs)
{
    lhs = lhs - rhs;
    return lhs;
}

/// <summary>
/// ベクトルの乗算代入
/// </summary>
/// <param name="lhs">ベクトル</param>
/// <param name="s">定数</param>
/// <returns>乗算後のベクトル</returns>
VECTOR operator*=(VECTOR& lhs, const float s)
{
    lhs = lhs * s;
    return lhs;
}