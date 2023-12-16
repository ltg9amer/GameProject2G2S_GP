#include "pch.h"
#include "CameraManager.h"
#include "Core.h"

void CameraManager::Init()
{
	lookAtPosition = (Vec2)Core::GetInst()->GetResolution() * .5f;
	targetObject = nullptr;
	moveSpeed = 1500.f;
}

void CameraManager::Update()
{
	if (targetObject) {
		lookAtPosition = targetObject->GetPos();
	}

	CalculateDifference();
}

void CameraManager::CalculateDifference()
{
	Vec2 resolution = Core::GetInst()->GetResolution();
	Vec2 centerPosition = resolution * .5f;
	difference = lookAtPosition - centerPosition;
}
