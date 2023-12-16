#pragma once
#include "Scene.h"
class Texture;
class UI;
class StartScene :
    public Scene
{
    UI* introUI;
public:
    virtual void Init() override;
    virtual void Render(HDC _dc) override;
    virtual void Update() override;
    virtual void Release() override;
};

