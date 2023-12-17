#pragma once
#include "FButton.h"

class FExitButton : public FButton {
public:
	FExitButton();

	~FExitButton();

	virtual void OnButtonClick() override;

	virtual void Render(HDC DeviceContext) override;

	virtual void Update() override;
};

