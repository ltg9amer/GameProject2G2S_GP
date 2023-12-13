#pragma once
class Object;
class CameraManager
{
	SINGLE(CameraManager);

	Object* targetObject;
	Vec2 lookAtPosition;
	Vec2 difference;
	float moveSpeed;

public:
	void Init();
	void Update();

public:
	const Object* GetTargetObject() const
	{
		return targetObject;
	}

	const Vec2 GetLookAtPosition() const
	{
		return lookAtPosition;
	}

	const Vec2 GetRenderPosition(Vec2 originPosition)
	{
		return (difference - originPosition) * -1;
	}

	const float& GetMoveSpeed() const {
		return moveSpeed;
	}

	void SetTargetObject(Object* object)
	{
		targetObject = object;
	}

	void SetLookAtPosition(Vec2 position)
	{
		lookAtPosition = position;
	}

private:
	void CalculateDifference();
};

