#pragma once

#include "DxLib.h"

// ĉÊĦ
const int ScreenW = 1920;

// ĉÊc
const int ScreenH = 1080;

/// <summary>
/// wiNX
/// </summary>
class Background
{
public:
    /// <summary>
    /// RXgN^
    /// </summary>
    Background();

    /// <summary>
    /// fXgN^
    /// </summary>
    ~Background();

    /// <summary>
    /// wiÌ`ĉ
    /// </summary>
    /// <param name="scrX"></param>
    /// <param name="scrY"></param>
    void Draw(int scrX, int scrY);

private:
    // wÊC[
    int back;

    // C[
    int mid;

    // OÊC[
    int front;

    // `ĉÀWx
    int drawX;

    // `ĉÀWy
    int drawY;

    // wiÀW
    VECTOR pos;
};