#pragma once
#include "FButton.h"

class FLeftArrowButton	: public FButton{
public:
	FLeftArrowButton();

	~FLeftArrowButton();

	virtual void OnButtonClick() override;

	virtual void Render(HDC DeviceContext) override;

	virtual void Update() override;
};

