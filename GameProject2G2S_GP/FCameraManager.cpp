#include "pch.h"
#include "FCameraManager.h"
#include "FCore.h"
#include "FObject.h"

void FCameraManager::Initialize() {
	TargetObject = nullptr;
	LookAtPosition = (FVector2)FCore::GetInstance()->GetResolution() * 0.5f;
	MoveSpeed = 1500.0f;
}

void FCameraManager::Update() {
	if (TargetObject) {
		LookAtPosition = TargetObject->GetPosition();
	}

	CalculateDifference();
}

void FCameraManager::CalculateDifference() {
	FVector2 Resolution = FCore::GetInstance()->GetResolution();
	FVector2 CenterPosition = Resolution * 0.5f;
	Difference = LookAtPosition - CenterPosition;
}
