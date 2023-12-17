#pragma once
#include "FObject.h"

class FTexture;

class FUserInterface;

class FUserInterfaceElement : public FObject {
protected:
	RECT InteractionRectangle;
	FTexture* Texture;
	FUserInterface* OwnerUserInterface;
	FVector2 AnchoredPosition;

public:
	FUserInterfaceElement();

	virtual ~FUserInterfaceElement();

	virtual void Render(HDC DeviceContext) override;

	virtual void Update() override;

	void SetAnchoredPosition(FVector2 AnchoredPosition) {
		this->AnchoredPosition = AnchoredPosition;
	}

	void SetOwnerUserInterface(FUserInterface* UserInterface) {
		OwnerUserInterface = UserInterface;
	}
};

