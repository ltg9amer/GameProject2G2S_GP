#include "pch.h"
#include "LeftArrowButton.h"
#include "PlayroomUI.h"

void PlayroomUI::Initialize()
{
	Button* leftArrowButton = new LeftArrowButton;

	leftArrowButton->SetAnchoredPosition(Vec2(-200, 0));
	leftArrowButton->SetOwnerUI(this);
	AddElement(leftArrowButton, UIElementGroup::Button);
}

void PlayroomUI::Update()
{
	UI::Update();
}

void PlayroomUI::Render(HDC _dc)
{
	UI::Render(_dc);
}

void PlayroomUI::Release()
{
	UI::Release();
}
