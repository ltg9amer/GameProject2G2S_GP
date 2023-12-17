#include "pch.h"
#include "FBedroomUserInterface.h"
#include "FImage.h"
#include "FLeftArrowButton.h"
#include "FRightArrowButton.h"

void FBedroomUserInterface::Initialize() {
	FButton* RightArrowButton = new FRightArrowButton;

	RightArrowButton->SetAnchoredPosition(FVector2(200, 0));
	RightArrowButton->SetOwnerUserInterface(this);
	AddElement(RightArrowButton, EUserInterfaceElementGroup::Button);
}

void FBedroomUserInterface::Release() {
	FUserInterface::Release();
}

void FBedroomUserInterface::Render(HDC DeviceContext) {
	FUserInterface::Render(DeviceContext);
}

void FBedroomUserInterface::Update() {
	FUserInterface::Update();
}
