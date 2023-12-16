#pragma once
#include "Button.h"
class ExitButton :
    public Button
{
public:
	ExitButton();

	~ExitButton();

	virtual void Update() override;

	virtual void Render(HDC _dc) override;

	virtual void OnButtonClick() override;
};

