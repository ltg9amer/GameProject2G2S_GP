#pragma once

class FAnimation;

class FObject;

class FTexture;

class FAnimator {
	friend class FObject;

	map<wstring, FAnimation*> Animations;
	FAnimation* CurrentAnimation;
	FObject* OwnerObject;
	bool bIsRepeat;
	int	RepeatCount;

public:
	FAnimator();

	~FAnimator();

	const bool& IsRepeat() const {
		return bIsRepeat;
	}

	const int& GetRepeatCount() const {
		return RepeatCount;
	}

	FAnimation* FindAnimation(const wstring& Name);

	FObject* GetOwnerObject() const {
		return OwnerObject;
	}

	void CreateAnimation(const wstring& Name, FTexture* Texture, FVector2 LeftTop, FVector2 FrameSliceSize, FVector2 FrameStepLength, UINT FrameCount, float FrameDuration);

	void PlayAnimation(const wstring& Name, bool bDoRepeat, int RepeatCount = 1);

	void Render(HDC DeviceContext);

	void SetRepeatCount() { 
		--RepeatCount; 
	}

	void Update();
};

