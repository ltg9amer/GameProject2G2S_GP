#include "pch.h"
#include "FAnimation.h"
#include "FAnimator.h"

FAnimator::FAnimator() : CurrentAnimation(nullptr), OwnerObject(nullptr), bIsRepeat(false), RepeatCount(0) {

}

FAnimator::~FAnimator() {
	map<wstring, FAnimation*>::iterator Iterator;

	for (Iterator = Animations.begin(); Iterator != Animations.end(); ++Iterator) {
		if (Iterator->second != nullptr) {
			delete Iterator->second;
		}
	}

	Animations.clear();
}

FAnimation* FAnimator::FindAnimation(const wstring& Name) {
	map<wstring, FAnimation*>::iterator iter = Animations.find(Name);

	if (iter == Animations.end()) {
		return nullptr;
	}

	return iter->second;
}

void FAnimator::CreateAnimation(const wstring& Name, FTexture* Texture, FVector2 LeftTop, FVector2 FrameSliceSize, FVector2 FrameStepLength, UINT FrameCount, float FrameDuration) {
	FAnimation* Animation = FindAnimation(Name);

	if (Animation != nullptr) {
		return;
	}

	Animation = new FAnimation;

	Animation->SetAnimationName(Name);

	Animation->OwnerAnimator = this;

	Animation->CreateAnimation(Texture, LeftTop, FrameSliceSize, FrameStepLength, FrameCount, FrameDuration);
	Animations.insert({ Name, Animation });
}

void FAnimator::PlayAnimation(const wstring& Name, bool bDoRepeat, int RepeatCount) {
	CurrentAnimation = FindAnimation(Name);
	bIsRepeat = bDoRepeat;
	this->RepeatCount = RepeatCount;
}

void FAnimator::Render(HDC DeviceContext) {
	if (CurrentAnimation != nullptr) {
		CurrentAnimation->Render(DeviceContext);
	}
}

void FAnimator::Update() {
	if (CurrentAnimation != nullptr) {
		CurrentAnimation->Update();
	}
}
