#pragma once
#include "Scene.h"
class Background;
class PlayScene :
    public Scene
{
    Background* background;

public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
};

