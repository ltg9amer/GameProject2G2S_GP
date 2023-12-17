#include "pch.h"
#include "FCameraManager.h"
#include "FCollider.h"
#include "FObject.h"
#include "FSelectGraphicDeviceInterface.h"

UINT FCollider::NextIdetifier = 0;

FCollider::FCollider() : Check(0), Identifier(NextIdetifier++), OwnerObject(nullptr), FinalPosition{}, Scale(FVector2(40.f, 40.f)) {

}

FCollider::FCollider(const FCollider& Original) : Check(0), Identifier(NextIdetifier++), OwnerObject(nullptr), FinalPosition{}, OffsetPosition(Original.OffsetPosition), Scale(Original.Scale) {

}

FCollider::~FCollider() {

}

void FCollider::EnterCollision(FCollider* Other) {
	++Check;

	OwnerObject->EnterCollision(Other);
}

void FCollider::ExitCollision(FCollider* Other) {
	--Check;

	OwnerObject->ExitCollision(Other);
}

void FCollider::FinalUpdate() {
	FVector2 OwnerPosition = OwnerObject->GetPosition();
	FinalPosition = OwnerPosition + OffsetPosition;
}

void FCollider::Render(HDC DeviceContext) {
	EPenType PenType = EPenType::Green;

	if (Check) {
		PenType = EPenType::Red;
	}

	FSelectGraphicDeviceInterface Pen(DeviceContext, PenType);
	FSelectGraphicDeviceInterface Brush(DeviceContext, EBrushType::Hollow);

	FVector2 RenderPosition = FCameraManager::GetInstance()->GetRenderPosition(FinalPosition);

	RECTANGLE_RENDER(RenderPosition.X, RenderPosition.Y, Scale.X, Scale.Y, DeviceContext);
}

void FCollider::StayCollision(FCollider* Other) {
	OwnerObject->StayCollision(Other);
}

