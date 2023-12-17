#include "pch.h"
#include "FCameraManager.h"
#include "FUserInterfaceElement.h"

FUserInterfaceElement::FUserInterfaceElement() : InteractionRectangle{}, Texture(nullptr), OwnerUserInterface(nullptr) {

}

FUserInterfaceElement::~FUserInterfaceElement() {

}

void FUserInterfaceElement::Render(HDC DeviceContext) {
	ComponentRender(DeviceContext);
}

void FUserInterfaceElement::Update() {
	FVector2 CameraPosition = FCameraManager::GetInstance()->GetLookAtPosition();
	Position = CameraPosition + AnchoredPosition;
	FVector2 RenderPosition = FCameraManager::GetInstance()->GetRenderPosition(Position);
	InteractionRectangle = { long(RenderPosition.X - Scale.X * 0.5f), long(RenderPosition.Y - Scale.Y * .5f), long(RenderPosition.X + Scale.X * 0.5f), long(RenderPosition.Y + Scale.Y * 0.5f) };
}
