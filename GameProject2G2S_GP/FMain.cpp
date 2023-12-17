#include "pch.h"
#include "FBaseWindow.h"

int APIENTRY wWinMain(_In_ HINSTANCE Instance, _In_opt_ HINSTANCE PreviewInstance, _In_ LPWSTR CommandLine, _In_ int CommandShow) {
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF);

	FBaseWindow Game({ WINDOW_WIDTH, WINDOW_HEIGHT });

	Game.Run(Instance, CommandLine, CommandShow);
}