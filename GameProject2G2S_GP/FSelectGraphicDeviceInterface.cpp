#include "pch.h"
#include "FCore.h"
#include "FSelectGraphicDeviceInterface.h"

FSelectGraphicDeviceInterface::FSelectGraphicDeviceInterface(HDC DeviceContext, EBrushType BrushType) : DefaultBrush(nullptr), DeviceContext(DeviceContext), DefaultFont(nullptr), Font(nullptr), DefaultPen(nullptr) {
	HBRUSH Brush = FCore::GetInstance()->GetBrush(BrushType);
	DefaultBrush = (HBRUSH)SelectObject(DeviceContext, Brush);
}

FSelectGraphicDeviceInterface::FSelectGraphicDeviceInterface(HDC DeviceContext, HFONT Font) : DefaultBrush(nullptr), DeviceContext(DeviceContext), DefaultFont(nullptr), Font(nullptr), DefaultPen(nullptr) {
	this->Font = Font;
	DefaultFont = (HFONT)SelectObject(DeviceContext, this->Font);
}

FSelectGraphicDeviceInterface::FSelectGraphicDeviceInterface(HDC DeviceContext, EPenType PenType) : DefaultBrush(nullptr), DeviceContext(DeviceContext), DefaultFont(nullptr), Font(nullptr), DefaultPen(nullptr) {
	HPEN Pen = FCore::GetInstance()->GetPen(PenType);
	DefaultPen = (HPEN)SelectObject(DeviceContext, Pen);
}

FSelectGraphicDeviceInterface::~FSelectGraphicDeviceInterface() {
	SelectObject(DeviceContext, DefaultPen);
	SelectObject(DeviceContext, DefaultBrush);
	SelectObject(DeviceContext, DefaultFont);

	if (Font != nullptr) {
		DeleteObject(Font);
	}
}
