#pragma once
#include "FScene.h"

class FTexture;

class FUserInterface;

class FStartScene : public FScene {
	FUserInterface* IntroUserInterface;

public:
	virtual void Initialize() override;

	virtual void Release() override;

	virtual void Render(HDC DeviceContext) override;

	virtual void Update() override;
};

