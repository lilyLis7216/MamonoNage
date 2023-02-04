#pragma once
#include <iostream>
#include <random>
#include <chrono>
#include <thread>



class ShakeMgr final
{
public: 
    /// <summary>
    /// �C���X�^���X�̐���
    /// </summary>
    static void CreateInstance();

    /// <summary>
    /// �C���X�^���X�̍폜
    /// </summary>
    static void DeleteInstance();

    static int GetShakePosX();
    static int GetShakePosY();
    static void ShakeScreen();

    static int ShakeX;
    static int ShakeY;

    static int SHAKE_PIXELS;
    static int SHAKE_DURATION;
    static int SHAKE_INTERVAL;

private:
    ShakeMgr();
    ~ShakeMgr();
    static ShakeMgr* mpInstance;
};

