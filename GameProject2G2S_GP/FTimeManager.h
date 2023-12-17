#pragma once

class FTimeManager {
	SINGLETON(FTimeManager);

	LARGE_INTEGER CurrentCount;
	LARGE_INTEGER Frequency;
	LARGE_INTEGER PreviewCount;
	UINT  FrameCount;
	UINT  FramePerSecond;
	float AccumulatedFrameTime;
	float DeltaTime;

public:
	const float& GetDeltaTime() const {
		return DeltaTime;
	}

	void Initialize();

	void Update();
};

