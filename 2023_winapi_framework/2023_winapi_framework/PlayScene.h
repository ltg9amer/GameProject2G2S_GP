#pragma once
#include "Scene.h"
class Background;
class UI;
class PlayScene :
    public Scene
{
    UINT currentRoom;
    Background* background;
    UI* currentRoomUI;

public:
    virtual void Init() override;

    virtual void Update() override;
    
    virtual void Render(HDC _dc) override;
    
    virtual void Release() override;
};

