#include "pch.h"
#include "FCameraManager.h"
#include "FImage.h"
#include "FResourceManager.h"
#include "FTexture.h"

FImage::FImage(wstring ImageName, float ScaleMultiflier){
	Texture = FResourceManager::GetInstance()->LoadTexture(ImageName, L"Texture\\" + ImageName + L".bmp");
	Scale = FVector2(Texture->GetWidth() * ScaleMultiflier, Texture->GetHeight() * ScaleMultiflier);
}

FImage::~FImage(){

}

void FImage::Render(HDC DeviceContext) {
	FVector2 RenderPosition = FCameraManager::GetInstance()->GetRenderPosition(Position);

	TransparentBlt(DeviceContext, RenderPosition.X - Scale.X * .5f, RenderPosition.Y - Scale.Y * .5f, Scale.X, Scale.Y, Texture->GetDC(), 0, 0, Texture->GetWidth(), Texture->GetHeight(), RGB(255, 0, 255));
	FUserInterfaceElement::Render(DeviceContext);
}

void FImage::Update(){
	FUserInterfaceElement::Update();
}
