#pragma once
#include "FObject.h"

class FTexture;

class FParva : public FObject {
	FTexture* Texture;
	float MoveSpeed;

public:
	FParva();

	~FParva();

	virtual void Render(HDC DeviceContext) override;

	virtual void Update() override;
};

