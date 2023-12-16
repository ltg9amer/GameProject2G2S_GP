#pragma once
#include "UIElement.h"
class Button :
    public UIElement
{
    bool isPressed;

public:
    Button();

    virtual ~Button();

    virtual void Update() override;

    virtual void Render(HDC _dc) override;

    virtual void OnButtonClick() abstract;
};

