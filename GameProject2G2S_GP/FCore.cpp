#include "pch.h"
#include "FCameraManager.h"
#include "FCollisionManager.h"
#include "FCore.h"
#include "FEventManager.h"
#include "FKeyManager.h"
#include "FPathManager.h"
#include "FResourceManager.h"
#include "FSceneManager.h"
#include "FTimeManager.h"

void FCore::GameLoop() {
	Update();
	Render();
}

void FCore::Release() {
	ReleaseDC(Window, MainDeviceContext);
	DeleteDC(BackDeviceContext);
	DeleteObject(BackBitmap);

	for (int i = 0; i < (UINT)EPenType::Last; ++i) {
		DeleteObject(Pens[i]);
	}

	for (int i = 1; i < (UINT)EBrushType::Last; ++i) {
		DeleteObject(Brushes[i]);
	}

	FResourceManager::GetInstance()->Release();
}

bool FCore::Initialize(HWND Window, POINT Resolution) {
	this->Window = Window;
	this->Resolution = Resolution;
	BackDeviceContext = 0;
	BackBitmap = 0;
	MainDeviceContext = GetDC(Window);
	BackBitmap = CreateCompatibleBitmap(MainDeviceContext, Resolution.x, Resolution.y);
	BackDeviceContext = CreateCompatibleDC(MainDeviceContext);

	SelectObject(BackDeviceContext, BackBitmap);
	CreateGraphicDeviceInterface();
	FCameraManager::GetInstance()->Initialize();
	FKeyManager::GetInstance()->Initialize();
	FPathManager::GetInstance()->Initialize();
	FResourceManager::GetInstance()->Initialize();
	FSceneManager::GetInstance()->Initialize();
	FTimeManager::GetInstance()->Initialize();

	return true;
}

void FCore::CreateGraphicDeviceInterface() {
	Brushes[(UINT)EBrushType::Blue] = (HBRUSH)CreateSolidBrush(RGB(103, 153, 255));
	Brushes[(UINT)EBrushType::Green] = (HBRUSH)CreateSolidBrush(RGB(134, 229, 134));
	Brushes[(UINT)EBrushType::Hollow] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	Brushes[(UINT)EBrushType::Red] = (HBRUSH)CreateSolidBrush(RGB(255, 167, 167));
	Brushes[(UINT)EBrushType::Yellow] = (HBRUSH)CreateSolidBrush(RGB(255, 187, 0));
	Pens[(UINT)EPenType::Blue] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	Pens[(UINT)EPenType::Green] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	Pens[(UINT)EPenType::Hollow] = CreatePen(PS_NULL, 0, RGB(0, 0, 0));
	Pens[(UINT)EPenType::Red] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	Pens[(UINT)EPenType::Yellow] = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
}

void FCore::Render() {
	PatBlt(BackDeviceContext, 0, 0, Resolution.x, Resolution.y, WHITENESS);
	FSceneManager::GetInstance()->Render(BackDeviceContext);
	BitBlt(MainDeviceContext, 0, 0, Resolution.x, Resolution.y, BackDeviceContext, 0, 0, SRCCOPY);
	FEventManager::GetInstance()->Update();
}

void FCore::Update() {
	FCameraManager::GetInstance()->Update();
	FCollisionManager::GetInstance()->Update();
	FKeyManager::GetInstance()->Update();
	FSceneManager::GetInstance()->Update();
	FTimeManager::GetInstance()->Update();
}
