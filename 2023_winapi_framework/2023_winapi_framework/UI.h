#pragma once
#include "Object.h"
class Scene;
class UIElement;
class UI :
    public Object
{
    vector<UIElement*> elements[(UINT)UIElementGroup::End];
    Scene* ownerScene;

public:
    UI();

    virtual ~UI();

    virtual void Initialize() abstract;

    virtual void Update() override;

    virtual void Render(HDC _dc) override;

    virtual void Release();

    const Scene* GetOwnerScene() const {
        return ownerScene;
    }

    vector<UIElement*> GetElementGroup(UIElementGroup elementGroup) {
        return elements[(UINT)elementGroup];
    }

    void AddElement(UIElement* element, UIElementGroup elementGroup) {
        elements[(UINT)elementGroup].push_back(element);
    }

    void SetOwnerScene(Scene* scene) {
        ownerScene = scene;
    }
};

