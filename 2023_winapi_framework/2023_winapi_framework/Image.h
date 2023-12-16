#pragma once
#include "UIElement.h"
class Texture;
class Image :
    public UIElement
{
    Texture* texture;

public:
    Image(wstring imageName, float scaleMultiflier);

    ~Image();

    virtual void Update() override;

    virtual void Render(HDC _dc) override;
};

