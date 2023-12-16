#pragma once
#include "Button.h"
#include "Food.h"
class BananaButton
	: public Button
{
public:
	Food ownerFood;
public:
	BananaButton();

	~BananaButton();

	virtual void Update() override;

	virtual void Render(HDC _dc) override;

	virtual void OnButtonClick() override;
};
