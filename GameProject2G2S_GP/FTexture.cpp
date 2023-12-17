#include <assert.h>
#include "pch.h"
#include "FCore.h"
#include "FTexture.h"

FTexture::FTexture() : BitmapInformation{}, Bitmap(0), DeviceContext(0) {

}

FTexture::~FTexture() {
	DeleteDC(DeviceContext);
	DeleteObject(Bitmap);
}

void FTexture::Load(const wstring& FilePath) {
	Bitmap = (HBITMAP)LoadImage(nullptr, FilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	assert(Bitmap);

	DeviceContext = CreateCompatibleDC(FCore::GetInstance()->GetMainDeviceContext());

	SelectObject(DeviceContext, Bitmap);
	GetObject(Bitmap, sizeof(BITMAP), &BitmapInformation);
}
