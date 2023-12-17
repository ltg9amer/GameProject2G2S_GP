#pragma once

class FSelectGraphicDeviceInterface {
	HBRUSH DefaultBrush;
	HDC	DeviceContext;
	HFONT DefaultFont;
	HFONT Font;
	HPEN DefaultPen;

public:
	FSelectGraphicDeviceInterface(HDC DeviceContext, EBrushType BrushType);

	FSelectGraphicDeviceInterface(HDC DeviceContext, HFONT Font);

	FSelectGraphicDeviceInterface(HDC DeviceContext, EPenType PenType);

	~FSelectGraphicDeviceInterface();
};
