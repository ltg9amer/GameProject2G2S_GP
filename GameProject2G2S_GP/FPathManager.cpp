#include "pch.h"
#include "FCore.h"
#include "FPathManager.h"

void FPathManager::Initialize() {
	GetCurrentDirectory(255, ResourcesPath);
	wcscat_s(ResourcesPath, 255, L"\\Res\\");
}
