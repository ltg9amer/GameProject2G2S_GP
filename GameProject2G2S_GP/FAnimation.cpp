#include "pch.h"
#include "FAnimation.h"
#include "FAnimator.h"
#include "FCameraManager.h"
#include "FObject.h"
#include "FTexture.h"
#include "FTimeManager.h"

FAnimation::FAnimation() : CurrentFrame(0), OwnerAnimator(nullptr), Texture(nullptr), AccumulatedTime(0.0f) {

}

FAnimation::~FAnimation() {

}

void FAnimation::CreateAnimation(FTexture* Texture,  FVector2& LeftTop, const FVector2& FrameSliceSize, FVector2& FrameStepLength, const int& FrameCount, const float& FrameDuration) {
	this->Texture = Texture;

	for (int i = 0; i < FrameCount; ++i) {
		Frames.push_back(FAnimationFrame({ LeftTop + FrameStepLength * i, { 0.0f, 0.0f }, FrameSliceSize, FrameDuration }));
	}
}

void FAnimation::Render(HDC DeviceContext) {
	FObject* OwnerObject = OwnerAnimator->GetOwnerObject();
	FVector2 OwnerPosition = OwnerObject->GetPosition();
	OwnerPosition = OwnerPosition + Frames[CurrentFrame].Offset;
	OwnerPosition = FCameraManager::GetInstance()->GetRenderPosition(OwnerPosition);

	TransparentBlt(DeviceContext, int(OwnerPosition.X - Frames[CurrentFrame].SliceSize.X * 0.5f), int(OwnerPosition.Y - Frames[CurrentFrame].SliceSize.Y * 0.5f), (int)Frames[CurrentFrame].SliceSize.X, (int)Frames[CurrentFrame].SliceSize.Y, Texture->GetDC(), (int)Frames[CurrentFrame].LeftTop.X, (int)Frames[CurrentFrame].LeftTop.Y, (int)Frames[CurrentFrame].SliceSize.X, (int)Frames[CurrentFrame].SliceSize.Y, RGB(255, 0, 255));
}

void FAnimation::Update() {
	if (OwnerAnimator->GetRepeatCount() <= 0) {
		return;
	}

	AccumulatedTime += DELTA_TIME;

	if (AccumulatedTime >= Frames[CurrentFrame].Duration) {
		AccumulatedTime -= Frames[CurrentFrame].Duration;
		++CurrentFrame;

		if (CurrentFrame >= Frames.size()) {
			if (!OwnerAnimator->IsRepeat()) {
				OwnerAnimator->SetRepeatCount();
			}

			CurrentFrame = 0;
			AccumulatedTime = 0.0f;
		}
	}
}
