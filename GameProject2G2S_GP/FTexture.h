#pragma once
#include "FResource.h"

class FTexture : public FResource {
	friend class FResourceManager;

	BITMAP BitmapInformation;
	HBITMAP Bitmap;
	HDC DeviceContext;

public:
	const HDC& GetDC() const {
		return DeviceContext;
	}

	const LONG& GetHeight() const {
		return BitmapInformation.bmHeight;
	}

	const LONG& GetWidth() const {
		return BitmapInformation.bmWidth;
	}

	void Load(const wstring& FilePath);

private:
	FTexture();

	~FTexture();
};

