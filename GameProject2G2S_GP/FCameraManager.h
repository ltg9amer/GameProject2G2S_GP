#pragma once

class FObject;

class FCameraManager {
	SINGLETON(FCameraManager);

	FObject* TargetObject;
	FVector2 LookAtPosition;
	FVector2 Difference;
	float MoveSpeed;

public:
	const FObject* GetTargetObject() const {
		return TargetObject;
	}

	const FVector2 GetLookAtPosition() const {
		return LookAtPosition;
	}

	const FVector2 GetRenderPosition(FVector2 OriginalPosition) {
		return (Difference - OriginalPosition) * -1;
	}

	const float& GetMoveSpeed() const {
		return MoveSpeed;
	}

	void Initialize();

	void SetTargetObject(FObject* Object) {
		TargetObject = Object;
	}

	void SetLookAtPosition(FVector2 SetPosition) {
		LookAtPosition = SetPosition;
	}

	void Update();

private:
	void CalculateDifference();
};

