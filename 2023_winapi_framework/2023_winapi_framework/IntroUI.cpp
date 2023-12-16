#include "pch.h"
#include "Button.h"
#include "ExitButton.h"
#include "Image.h"
#include "IntroUI.h"
#include "StartButton.h"

void IntroUI::Initialize()
{
	Image* introBackground = new Image(L"IntroBackground", 500.f / 490.f);
	Image* parva = new Image(L"Parva", .25f);
	Image* title = new Image(L"Title", 1.f);
	Button* startButton = new StartButton;
	Button* exitButton = new ExitButton;

	introBackground->SetAnchoredPosition(Vec2(0.f, 0.f));
	parva->SetAnchoredPosition(Vec2(-50.f, -225.f));
	title->SetAnchoredPosition(Vec2(0.f, -150.f));
	startButton->SetAnchoredPosition(Vec2(0.f, 50.f));
	exitButton->SetAnchoredPosition(Vec2(0.f, 200.f));
	AddElement(introBackground, UIElementGroup::Image);
	AddElement(parva, UIElementGroup::Image);
	AddElement(title, UIElementGroup::Image);
	AddElement(startButton, UIElementGroup::Button);
	AddElement(exitButton, UIElementGroup::Button);
}

void IntroUI::Update()
{
	UI::Update();
}

void IntroUI::Render(HDC _dc)
{
	UI::Render(_dc);
}

void IntroUI::Release()
{
	UI::Release();
}
