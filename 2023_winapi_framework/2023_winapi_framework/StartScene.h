#pragma once
#include "Scene.h"

class Texture;
class StartScene :
    public Scene
{
private:
    int TexSizeX;
    int TexSizeY;
    float start;
public:
    virtual void Init() override;
    virtual void Render(HDC _dc) override;
    virtual void Update() override;
    virtual void Release() override;
    virtual void FinalUpdate() override;
private:
    Texture* IntroBackground;
};

