#pragma once
#include "FUserInterface.h"

class FIntroUserInterface : public FUserInterface {
public:
	virtual void Initialize() override;

	virtual void Release() override;

	virtual void Render(HDC DeviceContext) override;

	virtual void Update() override;
};

