#include "pch.h"
#include "FKitchenUserInterface.h"
#include "FLeftArrowButton.h"
#include "FRightArrowButton.h"

void FKitchenUserInterface::Initialize() {
	FButton* LeftArrowButton = new FLeftArrowButton;
	FButton* RightArrowButton = new FRightArrowButton;

	LeftArrowButton->SetAnchoredPosition(FVector2(-200, 0));
	RightArrowButton->SetAnchoredPosition(FVector2(200, 0));
	LeftArrowButton->SetOwnerUserInterface(this);
	RightArrowButton->SetOwnerUserInterface(this);
	AddElement(LeftArrowButton, EUserInterfaceElementGroup::Button);
	AddElement(RightArrowButton, EUserInterfaceElementGroup::Button);
}

void FKitchenUserInterface::Release() {
	FUserInterface::Release();
}

void FKitchenUserInterface::Render(HDC DeviceContext) {
	FUserInterface::Render(DeviceContext);
}

void FKitchenUserInterface::Update() {
	FUserInterface::Update();
}
