#pragma once

#include "DxLib.h"

/// <summary>
/// ベクトル同士の加算
/// </summary>
/// <param name="lhs">1つ目のベクトル</param>
/// <param name="rhs">2つ目のベクトル</param>
/// <returns>加算後のベクトル</returns>
VECTOR operator+(const VECTOR& lhs, const VECTOR& rhs);

/// <summary>
/// ベクトル同士の減算
/// </summary>
/// <param name="lhs">1つ目のベクトル</param>
/// <param name="rhs">2つ目のベクトル</param>
/// <returns>減算後のベクトル</returns>
VECTOR operator-(const VECTOR& lhs, const VECTOR& rhs);

/// <summary>
/// ベクトルのスカラ倍（左定数）
/// </summary>
/// <param name="s">定数</param>
/// <param name="rhs">ベクトル</param>
/// <returns>乗算後のベクトル</returns>
VECTOR operator*(const float s, const VECTOR& rhs);

/// <summary>
/// ベクトルのスカラ倍（右定数）
/// </summary>
/// <param name="lhs">ベクトル</param>
/// <param name="s">定数</param>
/// <returns>乗算後のベクトル</returns>
VECTOR operator*(const VECTOR& lhs, const float s);

/// <summary>
/// ベクトルの加算代入
/// </summary>
/// <param name="lhs">代入されるのベクトル</param>
/// <param name="rhs">代入するベクトル</param>
/// <returns>加算後のベクトル</returns>
VECTOR operator+=(VECTOR& lhs, const VECTOR& rhs);

/// <summary>
/// ベクトルの減算代入
/// </summary>
/// <param name="lhs">代入されるベクトル</param>
/// <param name="rhs">代入するベクトル</param>
/// <returns>減算後のベクトル</returns>
VECTOR operator-=(VECTOR& lhs, const VECTOR& rhs);

/// <summary>
/// ベクトルの乗算代入
/// </summary>
/// <param name="lhs">ベクトル</param>
/// <param name="s">定数</param>
/// <returns>乗算後のベクトル</returns>
VECTOR operator*=(VECTOR& lhs, const float s);