#include "pch.h"
#include "Background.h"
#include "CameraManager.h"
#include "Core.h"
#include "KeyMgr.h"
#include "PlayScene.h"
#include "TimeMgr.h"
#include "BedroomUI.h"
#include "KitchenUI.h"
#include "PlayroomUI.h"

void PlayScene::Init()
{
	background = new Background;

	background->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f, Core::GetInst()->GetResolution().y / 2.f));
	AddObject(background, OBJECT_GROUP::BACKGROUND);

	vector<UI*> roomUIs(3);

	roomUIs[0] = new BedroomUI;
	roomUIs[1] = new KitchenUI;
	roomUIs[2] = new PlayroomUI;

	for (UINT i = 0; i < (UINT)RoomType::End; ++i) {
		roomUIs[i]->SetPos(background->GetCameraPosition(i));
		roomUIs[i]->Initialize();
		AddObject(roomUIs[i], OBJECT_GROUP::UI);
	}

	currentRoom = (UINT)RoomType::Kitchen;
	currentRoomUI = roomUIs[(UINT)currentRoom];
}

void PlayScene::Update()
{
	Vec2 cameraPosition = CameraManager::GetInst()->GetLookAtPosition();

	if (KEY_DOWN(KEY_TYPE::LEFT)) {
		if ((RoomType)currentRoom != RoomType::Bedroom) {
			currentRoomUI = (UI*)GetGroupObject(OBJECT_GROUP::UI)[--currentRoom];
		}
	}

	if (KEY_DOWN(KEY_TYPE::RIGHT)) {
		if ((RoomType)currentRoom != RoomType::Playroom) {
			currentRoomUI = (UI*)GetGroupObject(OBJECT_GROUP::UI)[++currentRoom];
		}
	}

	Vec2 curretRoomCameraPosition = background->GetCameraPosition(currentRoom);

	if (cameraPosition.x > curretRoomCameraPosition.x) {
		cameraPosition.x -= CameraManager::GetInst()->GetMoveSpeed() * fDT;

		if (cameraPosition.x < curretRoomCameraPosition.x) {
			cameraPosition.x = curretRoomCameraPosition.x;
		}
	}

	if (cameraPosition.x < curretRoomCameraPosition.x) {
		cameraPosition.x += CameraManager::GetInst()->GetMoveSpeed() * fDT;

		if (cameraPosition.x > curretRoomCameraPosition.x) {
			cameraPosition.x = curretRoomCameraPosition.x;
		}
	}

	CameraManager::GetInst()->SetLookAtPosition(cameraPosition);
	Scene::Update();
	currentRoomUI->Update();
}

void PlayScene::Render(HDC _dc)
{
	Scene::Render(_dc);
	currentRoomUI->Render(_dc);
}

void PlayScene::Release()
{
	Scene::Release();
}
