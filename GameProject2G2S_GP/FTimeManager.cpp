#include "pch.h"
#include "FCore.h"
#include "FTimeManager.h"
#include "Level.h"

void FTimeManager::Initialize() {
	FrameCount = 0;
	FramePerSecond = 0;
	AccumulatedFrameTime = 0.0f;

	QueryPerformanceCounter(&PreviewCount);
	QueryPerformanceFrequency(&Frequency);
}

void FTimeManager::Update() {
	Level LevelManager;

	QueryPerformanceCounter(&CurrentCount);

	DeltaTime = float(CurrentCount.QuadPart - PreviewCount.QuadPart) / (float)Frequency.QuadPart;
	PreviewCount = CurrentCount;
	FrameCount++;
	AccumulatedFrameTime += DeltaTime;

	if (AccumulatedFrameTime >= 1.f) {
		FramePerSecond = UINT(FrameCount / AccumulatedFrameTime);
		AccumulatedFrameTime = 0.f;
		FrameCount = 0;
		static wchar_t titlebuf[50] = {};

		swprintf_s(titlebuf, L"FPS: %d, DT: %f", FramePerSecond, DeltaTime);
		SetWindowText(FCore::GetInstance()->GetWindow(), titlebuf);
	}
}
