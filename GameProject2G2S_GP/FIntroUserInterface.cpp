#include "pch.h"
#include "FButton.h"
#include "FExitButton.h"
#include "FImage.h"
#include "FIntroUserInterface.h"
#include "FStartButton.h"

void FIntroUserInterface::Initialize() {
	FImage* IntroBackground = new FImage(L"IntroBackground", 500.f / 490.f);
	FImage* FParva = new FImage(L"Parva", .25f);
	FImage* Title = new FImage(L"Title", 1.f);
	FButton* StartButton = new FStartButton;
	FButton* ExitButton = new FExitButton;

	IntroBackground->SetAnchoredPosition(FVector2(0.f, 0.f));
	FParva->SetAnchoredPosition(FVector2(-50.f, -225.f));
	Title->SetAnchoredPosition(FVector2(0.f, -150.f));
	StartButton->SetAnchoredPosition(FVector2(0.f, 50.f));
	ExitButton->SetAnchoredPosition(FVector2(0.f, 200.f));
	AddElement(IntroBackground, EUserInterfaceElementGroup::Image);
	AddElement(FParva, EUserInterfaceElementGroup::Image);
	AddElement(Title, EUserInterfaceElementGroup::Image);
	AddElement(StartButton, EUserInterfaceElementGroup::Button);
	AddElement(ExitButton, EUserInterfaceElementGroup::Button);
}

void FIntroUserInterface::Release() {
	FUserInterface::Release();
}

void FIntroUserInterface::Render(HDC DeviceContext) {
	FUserInterface::Render(DeviceContext);
}

void FIntroUserInterface::Update() {
	FUserInterface::Update();
}
