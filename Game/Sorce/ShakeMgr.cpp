#include "ShakeMgr.h"

ShakeMgr* ShakeMgr::mpInstance = nullptr;

int ShakeMgr::ShakeX = 0;
int ShakeMgr::ShakeY = 0;
int ShakeMgr::SHAKE_PIXELS=10;
int ShakeMgr::SHAKE_DURATION=200;
int ShakeMgr::SHAKE_INTERVAL=20;

std::mt19937 engine(std::random_device{}());
std::uniform_int_distribution<int> shake_range(-10, 10);


ShakeMgr::ShakeMgr()
{
    mpInstance = nullptr;
}

ShakeMgr::~ShakeMgr()
{

}

void ShakeMgr::CreateInstance()
{
    if (!mpInstance)
    {
        mpInstance = new ShakeMgr;
    }
}

void ShakeMgr::DeleteInstance()
{
   
}

int ShakeMgr::GetShakePosX()
{
    ShakeX= shake_range(engine);
    return ShakeX;
}

int ShakeMgr::GetShakePosY()
{
    ShakeY= shake_range(engine);
    return ShakeY;
}

void ShakeMgr::ShakeScreen()
{
    for (int i = 0; i < SHAKE_PIXELS; i++) {
        std::cout << "Shaking screen! Position: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(SHAKE_INTERVAL));
    }
    for (int i = SHAKE_PIXELS - 1; i >= 0; i--) {
        std::cout << "Shaking screen! Position: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(SHAKE_INTERVAL));
    }
}
