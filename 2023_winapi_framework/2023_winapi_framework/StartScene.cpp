#include "pch.h"
#include "StartScene.h"
#include "Object.h"
#include "Core.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "ResMgr.h"
#include "Texture.h"
#include "CameraManager.h"
#include "IntroUI.h"

void StartScene::Init()
{
	CameraManager::GetInst()->SetLookAtPosition((Vec2)Core::GetInst()->GetResolution() * .5f);

	introUI = new IntroUI;

	introUI->Initialize();
	introUI->SetOwnerScene(this);
	introUI->SetPos(CameraManager::GetInst()->GetLookAtPosition());
	AddObject(introUI, OBJECT_GROUP::UI);
	ResMgr::GetInst()->LoadSound(L"IntroBGM", L"Sound\\IntroBGM.wav", true);
	ResMgr::GetInst()->Play(L"IntroBGM");
}

void StartScene::Update()
{
	Scene::Update();
	introUI->Update();
}

void StartScene::Render(HDC _dc)
{
	Scene::Render(_dc);
	introUI->Render(_dc);
}

void StartScene::Release()
{
	ResMgr::GetInst()->Stop(SOUND_CHANNEL::BGM);
}
