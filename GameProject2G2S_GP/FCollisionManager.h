#pragma once

class FCollider;

union UColliderIdentifier {
	struct {
		UINT LeftIdentifier;
		UINT RightIdentifier;
	};

	ULONGLONG Identifier;
};

class FCollisionManager {
	SINGLETON(FCollisionManager);

	map<ULONGLONG, bool> ColliderInformations;
	UINT CheckObjectGroups[(UINT)EObjectGroup::Last];

public:
	void CheckGroup(EObjectGroup Left, EObjectGroup Right);

	void CheckReset();

	void Update();

private:
	void CollisionGroupUpdate(EObjectGroup Left, EObjectGroup Right);

	bool IsCollision(FCollider* Left, FCollider* Right);
};

