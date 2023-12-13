#pragma once
#include "Object.h"
class Texture;
class Background :
    public Object
{
private:
    UINT currentScene;
    Texture* texture;
    Vec2 cameraPositionByScene[(UINT)SceneType::End];

public:
    Background();

    ~Background();

    const SceneType& GetCurrentScene() const {
        return (SceneType)currentScene;
    }

    const Vec2 GetCameraPosition(int index) const {
        return cameraPositionByScene[index];
    }

    void MoveLeftScene() {
        currentScene--;
    }

    void MoveRightScene() {
        currentScene++;
    }

    void Update() override;

    void Render(HDC _dc) override;
};

