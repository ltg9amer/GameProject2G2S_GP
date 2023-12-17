#include "pch.h"
#include "FLeftArrowButton.h"
#include "FPlayroomUserInterface.h"

void FPlayroomUserInterface::Initialize() {
	FButton* LeftArrowButton = new FLeftArrowButton;

	LeftArrowButton->SetAnchoredPosition(FVector2(-200, 0));
	LeftArrowButton->SetOwnerUserInterface(this);
	AddElement(LeftArrowButton, EUserInterfaceElementGroup::Button);
}

void FPlayroomUserInterface::Release() {
	FUserInterface::Release();
}

void FPlayroomUserInterface::Render(HDC DeviceContext) {
	FUserInterface::Render(DeviceContext);
}

void FPlayroomUserInterface::Update() {
	FUserInterface::Update();
}
