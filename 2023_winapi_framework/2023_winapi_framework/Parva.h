#pragma once
#include "Object.h"
class Texture;
class Parva :
    public Object
{
    Texture* texture;

public:
    Parva();

    ~Parva();

    virtual void Update() override;

    virtual void Render(HDC _hdc) override;
};

