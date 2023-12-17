#include "pch.h"
#include "FBackground.h"
#include "FCameraManager.h"
#include "FCore.h"
#include "FResourceManager.h"
#include "FTexture.h"

FBackground::FBackground() : Texture(nullptr), CameraPositions{ FVector2(-250.0f, FCore::GetInstance()->GetResolution().y * 0.5f), FVector2(250.0f, FCore::GetInstance()->GetResolution().y * 0.5f), FVector2(750.0f, FCore::GetInstance()->GetResolution().y * 0.5f) } {
	Texture = FResourceManager::GetInstance()->LoadTexture(L"Background", L"Texture\\Background.bmp");
	Scale = FVector2(Texture->GetWidth(), Texture->GetHeight());
}

FBackground::~FBackground() {

}

void FBackground::Render(HDC DeviceContext) {
	FVector2 RenderPosition = FCameraManager::GetInstance()->GetRenderPosition(Position);

	BitBlt(DeviceContext, int(RenderPosition.X - Scale.X * 0.5f), int(RenderPosition.Y - Scale.Y * 0.5f), Texture->GetWidth(), Texture->GetHeight(), Texture->GetDC(), 0, 0, SRCCOPY);
}

void FBackground::Update() {

}
