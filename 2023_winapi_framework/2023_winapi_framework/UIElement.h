#pragma once
#include "Object.h"
class Texture;
class UI;
class UIElement :
    public Object
{
protected:
    RECT interactionRectangle;
    Texture* texture;
    UI* ownerUI;
    Vec2 anchoredPosition;

public:
    UIElement();

    virtual ~UIElement();

    virtual void Update() override;

    virtual void Render(HDC _dc) override;

    void SetAnchoredPosition(Vec2 anchoredPosition) {
        this->anchoredPosition = anchoredPosition;
    }

    void SetOwnerUI(UI* ui) {
        ownerUI = ui;
    }
};

