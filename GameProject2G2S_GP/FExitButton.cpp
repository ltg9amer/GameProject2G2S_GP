#include "pch.h"
#include "FExitButton.h"
#include "FResourceManager.h"
#include "FTexture.h"

FExitButton::FExitButton() {
	Texture = FResourceManager::GetInstance()->LoadTexture(L"ExitButton", L"Texture\\ExitButton.bmp");
	Scale = FVector2(Texture->GetWidth() / 3.0f * 2.0f, Texture->GetHeight() / 3.0f * 2.0f);
}

FExitButton::~FExitButton() {
}

void FExitButton::OnButtonClick() {
	std::exit(1);
}

void FExitButton::Render(HDC DeviceContext) {
	FButton::Render(DeviceContext);
}

void FExitButton::Update() {
	FButton::Update();
}
