#pragma once

class FBaseWindow {
	POINT		Resolution;
	HINSTANCE	Instance;
	HWND		Window;

public:
	FBaseWindow(POINT Resolution);

	~FBaseWindow();

	static LRESULT CALLBACK WindowProcedure(HWND Window, UINT Message, WPARAM WordParameter, LPARAM LongParameter);

	ATOM MyRegisterClass();

	int MessageLoop();

	int Run(HINSTANCE Instance, LPWSTR CommandLine, int CommandShow);

	void WindowCreate();

	void WindowShow(int CommandShow);

	void WindowUpdate();
};

