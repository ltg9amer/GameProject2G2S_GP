#include "pch.h"
#include "BedroomUI.h"
#include "RightArrowButton.h"
#include "LeftArrowButton.h"

void BedroomUI::Initialize()
{
	Button* rightArrowButton = new RightArrowButton;

	rightArrowButton->SetAnchoredPosition(Vec2(200, 0));
	rightArrowButton->SetOwnerUI(this);
	AddElement(rightArrowButton, UIElementGroup::Button);
}

void BedroomUI::Update()
{
	UI::Update();
}

void BedroomUI::Render(HDC _dc)
{
	UI::Render(_dc);
}

void BedroomUI::Release()
{
	UI::Release();
}
