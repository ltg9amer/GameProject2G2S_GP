#include "pch.h"
#include "FCameraManager.h"
#include "FParva.h"
#include "FResourceManager.h"
#include "FTexture.h"
#include "FTimeManager.h"

FParva::FParva() : MoveSpeed(250.0f) {
	Texture = FResourceManager::GetInstance()->LoadTexture(L"Parva", L"Texture\\Parva.bmp");
	Scale = FVector2(Texture->GetWidth() / 3.0f, Texture->GetHeight() / 3.0f);
}

FParva::~FParva() {

}

void FParva::Render(HDC DeviceContext) {
	FVector2 RenderPosition = FCameraManager::GetInstance()->GetRenderPosition(Position);

	TransparentBlt(DeviceContext, int(RenderPosition.X - Scale.X * 0.5f), int(RenderPosition.Y - Scale.Y * 0.5f), Scale.X, Scale.Y, Texture->GetDC(), 0, 0, Texture->GetWidth(), Texture->GetHeight(), RGB(255, 0, 255));
}

void FParva::Update() {
	float CameraPositionX = FCameraManager::GetInstance()->GetLookAtPosition().X;

	if (CameraPositionX < Position.X) {
		Position.X -= MoveSpeed * DELTA_TIME;

		if (CameraPositionX > Position.X) {
			Position.X = CameraPositionX;
		}
	}

	if (CameraPositionX > Position.X) {
		Position.X += MoveSpeed * DELTA_TIME;

		if (CameraPositionX < Position.X) {
			Position.X = CameraPositionX;
		}
	}
}
