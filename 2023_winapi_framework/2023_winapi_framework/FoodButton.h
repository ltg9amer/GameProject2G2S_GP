#pragma once
#include "Button.h"
class FoodButton
	: public Button
{
public:
	FoodButton();

	~FoodButton();

	virtual void Update() override;

	virtual void Render(HDC _dc) override;
};
