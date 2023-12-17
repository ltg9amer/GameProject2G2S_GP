#pragma once
#include "define.h"
#include "FObject.h"

class FCore {
	SINGLETON(FCore);

	HBITMAP	BackBitmap;
	HBRUSH Brushes[(UINT)EBrushType::Last];
	HDC	BackDeviceContext;
	HDC	MainDeviceContext;
	HPEN Pens[(UINT)EPenType::Last];
	HWND Window;
	POINT Resolution;

public:
	const HBRUSH& GetBrush(EBrushType Type) {
		return Brushes[(UINT)Type];
	}

	const HDC& GetMainDeviceContext() const {
		return MainDeviceContext;
	}

	const HPEN& GetPen(EPenType Type) {
		return Pens[(UINT)Type];
	}

	const HWND& GetWindow() const {
		return Window;
	}

	const POINT& GetResolution() const {
		return Resolution;
	}

	void GameLoop();

	void Release();

	bool Initialize(HWND Window, POINT Resolution);

private:
	void CreateGraphicDeviceInterface();

	void Render();

	void Update();
};

