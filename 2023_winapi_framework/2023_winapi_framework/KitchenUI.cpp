#include "pch.h"
#include "KitchenUI.h"
#include "LeftArrowButton.h"
#include "RightArrowButton.h"

void KitchenUI::Initialize()
{
	Button* leftArrowButton = new LeftArrowButton;
	Button* rightArrowButton = new RightArrowButton;

	leftArrowButton->SetAnchoredPosition(Vec2(-200, 0));
	rightArrowButton->SetAnchoredPosition(Vec2(200, 0));
	leftArrowButton->SetOwnerUI(this);
	rightArrowButton->SetOwnerUI(this);
	AddElement(leftArrowButton, UIElementGroup::Button);
	AddElement(rightArrowButton, UIElementGroup::Button);
}

void KitchenUI::Update()
{
	UI::Update();
}

void KitchenUI::Render(HDC _dc)
{
	UI::Render(_dc);
}

void KitchenUI::Release()
{
	UI::Release();
}
