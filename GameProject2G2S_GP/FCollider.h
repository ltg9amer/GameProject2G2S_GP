#pragma once

class FObject;

class FCollider {
	friend class FObject;

	static UINT NextIdetifier;
	UINT Check;
	UINT Identifier;
	FObject* OwnerObject;
	FVector2 FinalPosition;
	FVector2 OffsetPosition;
	FVector2 Scale;

public:
	FCollider();

	FCollider(const FCollider& Original);

	~FCollider();

	FCollider& operator = (FCollider& Original) = delete;

	const UINT& GetIdentifier() const {
		return Identifier;
	}

	const FObject* GetOwnerObject() const {
		return OwnerObject;
	}

	const FVector2& GetFinalPosition() const {
		return FinalPosition;
	}

	const FVector2& GetOffSetPosition() const {
		return OffsetPosition;
	}

	const FVector2& GetScale() const {
		return Scale;
	}

	void EnterCollision(FCollider* Other);

	void ExitCollision(FCollider* Other);

	void FinalUpdate();

	void Render(HDC DeviceContext);

	void SetScale(FVector2 Scale) {
		this->Scale = Scale;
	}

	void StayCollision(FCollider* Other);

	void SetOffSetPos(FVector2 OffsetPosition) {
		this->OffsetPosition = OffsetPosition;
	}
};

