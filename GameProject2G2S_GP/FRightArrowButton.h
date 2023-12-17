#pragma once
#include "FButton.h"

class FRightArrowButton : public FButton {
public:
	FRightArrowButton();

	~FRightArrowButton();

	virtual void OnButtonClick() override;

	virtual void Render(HDC DeviceContext) override;

	virtual void Update() override;
};

