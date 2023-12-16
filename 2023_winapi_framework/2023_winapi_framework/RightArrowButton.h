#pragma once
#include "Button.h"
class RightArrowButton
	: public Button
{
public:
	RightArrowButton();

	~RightArrowButton();

	virtual void Update() override;

	virtual void Render(HDC _dc) override;

	virtual void OnButtonClick() override;
};

