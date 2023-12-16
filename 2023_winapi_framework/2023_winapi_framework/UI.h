#pragma once
#include "Object.h"
class UIElement;
class UI :
    public Object
{
    vector<UIElement*> elements[(UINT)UIElementGroup::End];

public:
    UI();

    virtual ~UI();

    virtual void Initialize() abstract;

    virtual void Update() override;

    virtual void Render(HDC _dc) override;

    virtual void Release();

    vector<UIElement*> GetElementGroup(UIElementGroup elementGroup) {
        return elements[(UINT)elementGroup];
    }

    void AddElement(UIElement* element, UIElementGroup elementGroup) {
        elements[(UINT)elementGroup].push_back(element);
    }
};

