#pragma once
#include "Button.h"
class StartButton :
    public Button
{
public:
	StartButton();

	~StartButton();

	virtual void Update() override;

	virtual void Render(HDC _dc) override;

	virtual void OnButtonClick() override;
};

