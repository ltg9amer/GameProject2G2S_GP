#pragma once

class FAnimator;

class FCollider;

class FObject {
	friend class FEventManager;

protected:
	wstring Name;
	FAnimator* Animator;
	FCollider* Collider;
	FVector2 Position;
	FVector2 Scale;
	bool bIsAlive;

public:
	FObject();

	virtual ~FObject();

	const wstring& GetName() const {
		return Name;
	}

	const FVector2& GetPosition() const {
		return Position;
	}

	const FVector2& GetScale() const {
		return Scale;
	}

	virtual void EnterCollision(FCollider* Other);

	virtual void ExitCollision(FCollider* Other);

	virtual void FinalUpdate() final;

	virtual void Render(HDC DeviceContext);

	virtual void StayCollision(FCollider* Other);

	virtual void Update();

	FAnimator* GetAnimator() {
		return Animator;
	}

	FCollider* GetCollider() const {
		return Collider;
	}

	void ComponentRender(HDC DeviceContext);

	void CreateAnimator();

	void CreateCollider();

	void SetName(wstring Name) {
		this->Name = Name;
	}

	void SetPosition(FVector2 Position) {
		this->Position = Position;
	}

	void SetScale(FVector2 Scale) {
		this->Scale = Scale;
	}

	bool IsDead() const {
		return !bIsAlive;
	}

private:
	void SetDead() {
		bIsAlive = false;
	}
};

