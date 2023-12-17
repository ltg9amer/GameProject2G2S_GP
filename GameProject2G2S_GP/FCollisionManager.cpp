#include "pch.h"
#include "FCollider.h"
#include "FCollisionManager.h"
#include "FObject.h"
#include "FScene.h"
#include "FSceneManager.h"

void FCollisionManager::CheckGroup(EObjectGroup Left, EObjectGroup Right) {
	UINT Row = (UINT)Left;
	UINT Column = (UINT)Right;

	if (Row > Column) {
		std::swap(Row, Column);
	}

	if (CheckObjectGroups[Row] & (1 << Column)) {
		CheckObjectGroups[Row] &= ~(1 << Column);
	}
	else {
		CheckObjectGroups[Row] |= (1 << Column);
	}
}

void FCollisionManager::CheckReset() {
	memset(CheckObjectGroups, 0, sizeof(UINT) * (UINT)(EObjectGroup::Last));
}

void FCollisionManager::Update() {
	for (UINT Row = 0; Row < (UINT)EObjectGroup::Last; ++Row) {
		for (UINT Column = Row; Column < (UINT)EObjectGroup::Last; ++Column) {
			if (CheckObjectGroups[Row] & (1 << Column)) {
				CollisionGroupUpdate((EObjectGroup)Row, (EObjectGroup)Column);
			}
		}
	}
}
void FCollisionManager::CollisionGroupUpdate(EObjectGroup Left, EObjectGroup Right) {
	std::shared_ptr<FScene> CurrentScene = FSceneManager::GetInstance()->GetCurrentScene();
	const vector<FObject*>& LeftObjects = CurrentScene->GetObjectsOfGroup(Left);
	const vector<FObject*>& RightObjects = CurrentScene->GetObjectsOfGroup(Right);

	for (size_t i = 0; i < LeftObjects.size(); ++i) {
		if (LeftObjects[i]->GetCollider() == nullptr) {
			continue;
		}

		for (size_t j = 0; j < RightObjects.size(); ++j) {
			if (RightObjects[j]->GetCollider() == nullptr || LeftObjects[i] == RightObjects[j]) {
				continue;
			}

			FCollider* LeftCollider = LeftObjects[i]->GetCollider();
			FCollider* RightCollider = RightObjects[j]->GetCollider();

			UColliderIdentifier ColliderIdentifier;

			ColliderIdentifier.LeftIdentifier = LeftCollider->GetIdentifier();
			ColliderIdentifier.RightIdentifier = RightCollider->GetIdentifier();
			auto Iterator = ColliderInformations.find(ColliderIdentifier.Identifier);

			if (Iterator == ColliderInformations.end()) {
				ColliderInformations.insert({ ColliderIdentifier.Identifier, false });

				Iterator = ColliderInformations.find(ColliderIdentifier.Identifier);
			}

			if (IsCollision(LeftCollider, RightCollider)) {
				if (Iterator->second) {
					if (LeftObjects[i]->IsDead() || RightObjects[j]->IsDead()) {
						LeftCollider->ExitCollision(RightCollider);
						RightCollider->ExitCollision(LeftCollider);

						Iterator->second = false;
					}
					else {
						LeftCollider->StayCollision(RightCollider);
						RightCollider->StayCollision(LeftCollider);
					}
				}
				else {
					LeftCollider->EnterCollision(RightCollider);
					RightCollider->EnterCollision(LeftCollider);

					Iterator->second = true;
				}
			}
			else {
				if (Iterator->second) {
					LeftCollider->ExitCollision(RightCollider);
					RightCollider->ExitCollision(LeftCollider);

					Iterator->second = false;
				}
			}
		}
	}
}

bool FCollisionManager::IsCollision(FCollider* Left, FCollider* Right) {
	FVector2 LeftPosition = Left->GetFinalPosition();
	FVector2 RightPosition = Right->GetFinalPosition();
	FVector2 LeftScale = Left->GetScale();
	FVector2 RightScale = Right->GetScale();

	if (abs(RightPosition.X - LeftPosition.X) < (LeftScale.X + RightScale.X) * 0.5f && abs(RightPosition.Y - LeftPosition.Y) < (LeftScale.Y + RightScale.Y) * 0.5f) {
		return true;
	}

	return false;
}

