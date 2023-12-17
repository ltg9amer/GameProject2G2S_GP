#pragma once
#include "FUserInterfaceElement.h"

class FButton : public FUserInterfaceElement {
	bool bIsPressed;

public:
	FButton();

	~FButton();

	virtual void OnButtonClick() abstract;

	virtual void Render(HDC DeviceContext) override;

	virtual void Update() override;
};

