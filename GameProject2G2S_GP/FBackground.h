#pragma once
#include "FObject.h"

class FTexture;

class FBackground : public FObject {
	FTexture* Texture;
	FVector2 CameraPositions[(UINT)ERoomType::Last];

public:
	FBackground();

	~FBackground();

	const FVector2 GetCameraPosition(int Index) const {
		return CameraPositions[Index];
	}

	void Render(HDC DeviceContext) override;

	void Update() override;
};

