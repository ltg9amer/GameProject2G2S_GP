#include "pch.h"
#include "FBaseWindow.h"
#include "FCore.h"
#include "Resource.h"

FBaseWindow::FBaseWindow(POINT Resolution) : Resolution(Resolution), Instance(0), Window(0) {

}

FBaseWindow::~FBaseWindow() {

}

LRESULT FBaseWindow::WindowProcedure(HWND Window, UINT Message, WPARAM WordParameter, LPARAM LongParameter) {
	switch (Message) {
	case WM_DESTROY: {
		PostQuitMessage(0);
	}

				   break;

	default:
		return DefWindowProc(Window, Message, WordParameter, LongParameter);
	}

	return 0;
}

ATOM FBaseWindow::MyRegisterClass() {
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = FBaseWindow::WindowProcedure;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = Instance;
	wcex.hIcon = LoadIcon(Instance, MAKEINTRESOURCE(IDI_SMALL));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = WINDOW_CLASS_NAME;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

int FBaseWindow::MessageLoop() {
	MSG Message;

	while (true) {
		if (PeekMessage(&Message, nullptr, 0, 0, PM_REMOVE)) {
			if (Message.message == WM_QUIT) {
				break;
			}

			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		else {
			FCore::GetInstance()->GameLoop();
		}
	}

	FCore::GetInstance()->Release();

	return (int)Message.wParam;
}

int FBaseWindow::Run(HINSTANCE Instance, LPWSTR CommandLine, int CommandShow) {
	Instance = Instance;

	this->MyRegisterClass();
	this->WindowCreate();
	this->WindowShow(CommandShow);
	this->WindowUpdate();

	if (!FCore::GetInstance()->Initialize(Window, Resolution)) {
		MessageBox(Window, L"Core 초기화 실패", L"Fail", MB_OK);
	}

	return this->MessageLoop();
}

void FBaseWindow::WindowCreate() {
	int WindowPositionX = GetSystemMetrics(SM_CXSCREEN) * 0.5f - Resolution.x * 0.5f;
	int WindowPositionY = GetSystemMetrics(SM_CYSCREEN) * 0.5f - Resolution.y * 0.5f;
	Window = CreateWindowW(WINDOW_CLASS_NAME, L"Parva", WS_OVERLAPPEDWINDOW, WindowPositionX, WindowPositionY, Resolution.x, Resolution.y, nullptr, nullptr, Instance, nullptr);
	RECT Rectangle = { WindowPositionX, WindowPositionY, WindowPositionX + Resolution.x, WindowPositionY + Resolution.y };

	AdjustWindowRect(&Rectangle, WS_OVERLAPPEDWINDOW, false);
	MoveWindow(Window, WindowPositionX, WindowPositionY, Rectangle.right - Rectangle.left, Rectangle.bottom - Rectangle.top, true);
}

void FBaseWindow::WindowShow(int CommandShow) {
	ShowWindow(Window, CommandShow);
}

void FBaseWindow::WindowUpdate() {
	UpdateWindow(Window);
}
