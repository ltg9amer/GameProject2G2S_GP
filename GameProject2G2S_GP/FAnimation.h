#pragma once

struct FAnimationFrame {
	FVector2 LeftTop;
	FVector2 Offset;
	FVector2 SliceSize;
	float Duration;
};

class FAnimator;

class FTexture;

class FAnimation {
	friend class FAnimator;

	vector<FAnimationFrame> Frames;
	UINT CurrentFrame;
	wstring Name;
	FAnimator* OwnerAnimator;
	FTexture* Texture;
	int RepeatCount;
	float AccumulatedTime;

public:
	FAnimation();

	~FAnimation();

	const size_t& GetMaxFrame() const {
		return Frames.size();
	}

	const wstring& GetName() const {
		return Name;
	}

	void CreateAnimation(FTexture* Texture, FVector2& LeftTop, const FVector2& FrameSliceSize, FVector2& FrameStepLength, const int& FrameCount, const float& FrameDuration);

	void Render(HDC DeviceContext);

	void SetAnimationName(const wstring& AnimationName) {
		Name = AnimationName;
	}

	void SetFrameOffset(const int& Index, const FVector2& Offset) {
		Frames[Index].Offset = Offset;
	}

	void Update();
};

