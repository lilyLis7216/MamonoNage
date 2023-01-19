#pragma once

#include "SceneBase.h"

class Play : public SceneBase
{
public:
    Play();
    ~Play();

    SceneBase* Update(float _deltaTime) override;

    void Draw() override;
};