#include "pch.h"
#include "FParva.h"
#include "FResourceManager.h"
#include "FTexture.h"

FParva::FParva() {
	Texture = FResourceManager::GetInstance()->LoadTexture(L"Parva", L"Texture\\Parva.bmp");
	Scale = FVector2(Texture->GetWidth() * 0.75f, Texture->GetHeight() * 0.75f);
}

FParva::~FParva() {

}

void FParva::Render(HDC DeviceContext) {

}

void FParva::Update() {

}
