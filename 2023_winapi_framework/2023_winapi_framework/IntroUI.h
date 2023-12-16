#pragma once
#include "UI.h"
class IntroUI :
    public UI
{
public:
    virtual void Initialize() override;

    virtual void Update() override;

    virtual void Render(HDC _dc) override;

    virtual void Release() override;
};

