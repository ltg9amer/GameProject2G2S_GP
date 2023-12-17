#pragma once
#include "FButton.h"

class FStartButton : public FButton {
public:
	FStartButton();

	~FStartButton();

	virtual void OnButtonClick() override;

	virtual void Render(HDC DeviceContext) override;

	virtual void Update() override;
};

