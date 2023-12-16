#pragma once
#include "Object.h"
class Texture;
class Background :
    public Object
{
private:
    Texture* texture;
    Vec2 cameraPositionsByRoom[(UINT)RoomType::End];

public:
    Background();

    ~Background();

    const Vec2 GetCameraPosition(int index) const {
        return cameraPositionsByRoom[index];
    }

    void Update() override;

    void Render(HDC _dc) override;
};

