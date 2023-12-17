#include "pch.h"
#include "FResourceManager.h"
#include "FSceneManager.h"
#include "FStartButton.h"
#include "FTexture.h"

FStartButton::FStartButton() {
	Texture = FResourceManager::GetInstance()->LoadTexture(L"StartButton", L"Texture\\StartButton.bmp");
	Scale = FVector2(Texture->GetWidth(), Texture->GetHeight());
}

FStartButton::~FStartButton() {

}

void FStartButton::OnButtonClick() {
	FSceneManager::GetInstance()->LoadScene(L"PlayScene");
}

void FStartButton::Render(HDC DeviceContext) {
	FButton::Render(DeviceContext);
}

void FStartButton::Update() {
	FButton::Update();
}
