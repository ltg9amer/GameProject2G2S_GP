#pragma once
#include "Button.h"
class LeftArrowButton
	: public Button
{
public:
	LeftArrowButton();

	~LeftArrowButton();

	virtual void Update() override;

	virtual void Render(HDC _dc) override;
};

