#include "pch.h"
#include "FLeftArrowButton.h"
#include "FPlayScene.h"
#include "FResourceManager.h"
#include "FTexture.h"
#include "FUserInterface.h"

FLeftArrowButton::FLeftArrowButton(){
	Texture = FResourceManager::GetInstance()->LoadTexture(L"LeftArrowButton", L"Texture\\LeftArrow.bmp");
	Scale = FVector2(Texture->GetWidth() / 3.0f, Texture->GetHeight() / 3.0f);
}

FLeftArrowButton::~FLeftArrowButton(){

}

void FLeftArrowButton::OnButtonClick() {
	((FPlayScene*)OwnerUserInterface->GetOwnerScene())->MoveLeftRoom();
}

void FLeftArrowButton::Render(HDC DeviceContext) {
	FButton::Render(DeviceContext);
}

void FLeftArrowButton::Update(){
	FButton::Update();
}
