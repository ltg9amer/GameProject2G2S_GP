#pragma once
#include "Scene.h"
class Start_Scene :
    public Scene
{
    void Init();
    void Update();
    void Render(HDC _dc);
    void Release();
};

