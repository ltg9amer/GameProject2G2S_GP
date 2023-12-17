#include "pch.h"
#include "FAnimator.h"
#include "FCameraManager.h"
#include "FCollider.h"
#include "FKeyManager.h"
#include "FObject.h"
#include "FTimeManager.h"

FObject::FObject() : Animator(nullptr), Collider(nullptr), Position{}, Scale{}, bIsAlive(true) {

}

FObject::~FObject() {
	if (Animator != nullptr) {
		delete Animator;
	}

	if (Collider != nullptr) {
		delete Collider;
	}
}

void FObject::EnterCollision(FCollider* Other) {

}

void FObject::ExitCollision(FCollider* Other) {

}

void FObject::FinalUpdate() {
	if (Collider) {
		Collider->FinalUpdate();
	}
}

void FObject::Render(HDC DeviceContext) {
	FVector2 RenderPosition = FCameraManager::GetInstance()->GetRenderPosition(Position);

	RECTANGLE_RENDER(RenderPosition.X, RenderPosition.Y, Scale.X, Scale.Y, DeviceContext);
	ComponentRender(DeviceContext);
}

void FObject::StayCollision(FCollider* Other) {

}

void FObject::Update() {

}

void FObject::ComponentRender(HDC DeviceContext) {
	if (Animator != nullptr) {
		Animator->Render(DeviceContext);
	}

	if (Collider != nullptr) {
		Collider->Render(DeviceContext);
	}
}

void FObject::CreateCollider() {
	Collider = new FCollider;
	Collider->OwnerObject = this;
}

void FObject::CreateAnimator() {
	Animator = new FAnimator;
	Animator->OwnerObject = this;
}

