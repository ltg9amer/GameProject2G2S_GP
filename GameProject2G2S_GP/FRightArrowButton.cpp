#include "pch.h"
#include "FPlayScene.h"
#include "FResourceManager.h"
#include "FRightArrowButton.h"
#include "FTexture.h"
#include "FUserInterface.h"

FRightArrowButton::FRightArrowButton() {
	Texture = FResourceManager::GetInstance()->LoadTexture(L"RightArrowButton", L"Texture\\RightArrow.bmp");
	Scale = FVector2(Texture->GetWidth() / 3.0f, Texture->GetHeight() / 3.0f);
}

FRightArrowButton::~FRightArrowButton() {

}

void FRightArrowButton::OnButtonClick() {
	((FPlayScene*)OwnerUserInterface->GetOwnerScene())->MoveRightRoom();
}

void FRightArrowButton::Render(HDC DeviceContext) {
	FButton::Render(DeviceContext);
}

void FRightArrowButton::Update() {
	FButton::Update();
}
