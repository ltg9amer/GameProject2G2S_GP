#include "pch.h"
#include "FButton.h"
#include "FCameraManager.h"
#include "FEventManager.h"
#include "FKeyManager.h"
#include "FTexture.h"

FButton::FButton() : bIsPressed(false) {

}

FButton::~FButton() {
}

void FButton::Render(HDC DeviceContext) {
	long width = Texture->GetWidth(), height = Texture->GetHeight();

	if (bIsPressed) {
		TransparentBlt(DeviceContext, InteractionRectangle.left + Scale.X * .1f, InteractionRectangle.top + Scale.Y * .1f, Scale.X * .8f, Scale.Y * .8f, Texture->GetDC(), 0, 0, width, height, RGB(255, 0, 255));
	}
	else {
		TransparentBlt(DeviceContext, InteractionRectangle.left, InteractionRectangle.top, Scale.X, Scale.Y, Texture->GetDC(), 0, 0, width, height, RGB(255, 0, 255));
	}

	FUserInterfaceElement::Render(DeviceContext);
}

void FButton::Update() {
	FUserInterfaceElement::Update();

	if (KEY_DOWN(EKeyType::LeftMouseButton)) {
		FVector2 MousePosition = FKeyManager::GetInstance()->GetMousePosition();

		if (MousePosition.X >= InteractionRectangle.left && MousePosition.X <= InteractionRectangle.right && MousePosition.Y >= InteractionRectangle.top && MousePosition.Y <= InteractionRectangle.bottom) {
			bIsPressed = true;
		}
	}

	if (bIsPressed && KEY_UP(EKeyType::LeftMouseButton)) {
		FVector2 MousePosition = FKeyManager::GetInstance()->GetMousePosition();

		if (MousePosition.X >= InteractionRectangle.left && MousePosition.X <= InteractionRectangle.right && MousePosition.Y >= InteractionRectangle.top && MousePosition.Y <= InteractionRectangle.bottom) {
			FEventManager::GetInstance()->ClickButton(this);
		}

		bIsPressed = false;
	}
}
