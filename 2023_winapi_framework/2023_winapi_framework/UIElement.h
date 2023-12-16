#pragma once
#include "Object.h"
class Texture;
class UIElement :
    public Object
{
protected:
    RECT interactionRectangle;
    Texture* texture;
    Vec2 anchoredPosition;

public:
    UIElement();

    virtual ~UIElement();

    virtual void Update() override;

    virtual void Render(HDC _dc) override;

    void SetAnchoredPosition(Vec2 anchoredPosition) {
        this->anchoredPosition = anchoredPosition;
    }
};

