#include "pch.h"
#include "Background.h"
#include "CameraManager.h"
#include "Core.h"
#include "KeyMgr.h"
#include "PlayScene.h"
#include "TimeMgr.h"

void PlayScene::Init()
{
	background = new Background;

	background->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f, Core::GetInst()->GetResolution().y / 2.f));
	AddObject(background, OBJECT_GROUP::BACKGROUND);
}

void PlayScene::Update()
{
	Vec2 cameraPosition = CameraManager::GetInst()->GetLookAtPosition();

	if (KEY_DOWN(KEY_TYPE::LEFT) || KEY_DOWN(KEY_TYPE::LBUTTON)) {
		if (background->GetCurrentScene() != SceneType::Bedroom) {
			background->MoveLeftScene();
		}
	}

	if (KEY_DOWN(KEY_TYPE::RIGHT) || KEY_DOWN(KEY_TYPE::RBUTTON)) {
		if (background->GetCurrentScene() != SceneType::Playroom) {
			background->MoveRightScene();
		}
	}

	if (cameraPosition.x > background->GetCameraPosition((UINT)background->GetCurrentScene()).x) {
		cameraPosition.x -= CameraManager::GetInst()->GetMoveSpeed() * fDT;

		if (cameraPosition.x < background->GetCameraPosition((UINT)background->GetCurrentScene()).x) {
			cameraPosition.x = background->GetCameraPosition((UINT)background->GetCurrentScene()).x;
		}
	}

	if (cameraPosition.x < background->GetCameraPosition((UINT)background->GetCurrentScene()).x) {
		cameraPosition.x += CameraManager::GetInst()->GetMoveSpeed() * fDT;

		if (cameraPosition.x > background->GetCameraPosition((UINT)background->GetCurrentScene()).x) {
			cameraPosition.x = background->GetCameraPosition((UINT)background->GetCurrentScene()).x;
		}
	}

	CameraManager::GetInst()->SetLookAtPosition(cameraPosition);

	Scene::Update();
}

void PlayScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void PlayScene::Release()
{
	Scene::Release();
}
