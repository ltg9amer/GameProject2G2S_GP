#pragma once
#include "FUserInterfaceElement.h"

class FTexture;

class FImage : public FUserInterfaceElement {
public:
	FImage(wstring Name, float ScaleMultiflier);

	~FImage();

	virtual void Render(HDC DeviceContext) override;

	virtual void Update() override;
};

