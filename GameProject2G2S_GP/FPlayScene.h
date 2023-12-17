#pragma once
#include "FScene.h"

class FBackground;

class FUserInterface;

class FPlayScene : public FScene {
	UINT CurrentRoom;
	FBackground* Background;
	FUserInterface* CurrentRoomUserInterface;

public:
	virtual void Initialize() override;

	virtual void Release() override;

	virtual void Render(HDC DeviceContext) override;

	virtual void Update() override;

	void MoveLeftRoom();

	void MoveRightRoom();
};

