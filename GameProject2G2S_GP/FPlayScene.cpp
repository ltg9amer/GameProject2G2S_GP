#include "pch.h"
#include "FBackground.h"
#include "FBedroomUserInterface.h"
#include "FCameraManager.h"
#include "FCore.h"
#include "FKeyManager.h"
#include "FKitchenUserInterface.h"
#include "FParva.h"
#include "FPlayroomUserInterface.h"
#include "FPlayScene.h"
#include "FResourceManager.h"
#include "FSceneManager.h"
#include "FTimeManager.h"

void FPlayScene::Initialize() {
	Background = new FBackground;

	Background->SetPosition(FVector2(FCore::GetInstance()->GetResolution().x * 0.5f, FCore::GetInstance()->GetResolution().y * 0.5f));
	AddObject(Background, EObjectGroup::Background);

	FObject* Parva = new FParva;

	Parva->SetPosition(FVector2(FCore::GetInstance()->GetResolution().x * 0.5f, FCore::GetInstance()->GetResolution().y * 0.5f + 175.0f));
	AddObject(Parva, EObjectGroup::Character);

	vector<FUserInterface*> UserInterfaces(3);

	UserInterfaces[0] = new FBedroomUserInterface;
	UserInterfaces[1] = new FKitchenUserInterface;
	UserInterfaces[2] = new FPlayroomUserInterface;

	for (UINT i = 0; i < (UINT)ERoomType::Last; ++i) {
		UserInterfaces[i]->Initialize();
		UserInterfaces[i]->SetOwnerScene(this);
		UserInterfaces[i]->SetPosition(Background->GetCameraPosition(i));
		AddObject(UserInterfaces[i], EObjectGroup::UserInterface);
	}

	CurrentRoom = (UINT)ERoomType::Kitchen;
	CurrentRoomUserInterface = UserInterfaces[(UINT)CurrentRoom];

	FResourceManager::GetInstance()->LoadSound(L"PlayBGM", L"Sound\\Caketown.mp3", true);
	FResourceManager::GetInstance()->PlaySoundByKey(L"PlayBGM");
}

void FPlayScene::Release() {
	FScene::Release();
}

void FPlayScene::Render(HDC DeviceContext) {
	FScene::Render(DeviceContext);
	CurrentRoomUserInterface->Render(DeviceContext);
}

void FPlayScene::Update() {
	FVector2 CameraPosition = FCameraManager::GetInstance()->GetLookAtPosition();

	if (KEY_DOWN(EKeyType::Left)) {
		MoveLeftRoom();
	}

	if (KEY_DOWN(EKeyType::Right)) {
		MoveRightRoom();
	}

	FVector2 CameraDestination = Background->GetCameraPosition(CurrentRoom);

	if (CameraPosition.X > CameraDestination.X) {
		CameraPosition.X -= FCameraManager::GetInstance()->GetMoveSpeed() * DELTA_TIME;

		if (CameraPosition.X < CameraDestination.X) {
			CameraPosition.X = CameraDestination.X;
		}
	}

	if (CameraPosition.X < CameraDestination.X) {
		CameraPosition.X += FCameraManager::GetInstance()->GetMoveSpeed() * DELTA_TIME;

		if (CameraPosition.X > CameraDestination.X) {
			CameraPosition.X = CameraDestination.X;
		}
	}

	CurrentRoomUserInterface->Update();
	FCameraManager::GetInstance()->SetLookAtPosition(CameraPosition);
	FScene::Update();
}

void FPlayScene::MoveLeftRoom() {
	if ((ERoomType)CurrentRoom != ERoomType::Bedroom) {
		CurrentRoomUserInterface = (FUserInterface*)GetObjectsOfGroup(EObjectGroup::UserInterface)[--CurrentRoom];
	}
}

void FPlayScene::MoveRightRoom() {
	if ((ERoomType)CurrentRoom != ERoomType::Playroom) {
		CurrentRoomUserInterface = (FUserInterface*)GetObjectsOfGroup(EObjectGroup::UserInterface)[++CurrentRoom];
	}
}
