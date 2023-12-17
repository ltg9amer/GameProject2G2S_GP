#pragma once
#include "FUserInterface.h"

class FKitchenUserInterface : public FUserInterface {
public:
	virtual void Initialize() override;

	virtual void Release() override;

	virtual void Render(HDC DeviceContext) override;

	virtual void Update() override;
};

