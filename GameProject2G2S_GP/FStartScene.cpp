#include "pch.h"
#include "FStartScene.h"
#include "FCameraManager.h"
#include "FCore.h"
#include "FIntroUserInterface.h"
#include "FKeyManager.h"
#include "FObject.h"
#include "FResourceManager.h"
#include "FSceneManager.h"
#include "FTexture.h"
#include "FTimeManager.h"

void FStartScene::Initialize() {
	FCameraManager::GetInstance()->SetLookAtPosition((FVector2)FCore::GetInstance()->GetResolution() * 0.5f);

	IntroUserInterface = new FIntroUserInterface;

	IntroUserInterface->Initialize();
	IntroUserInterface->SetOwnerScene(this);
	IntroUserInterface->SetPosition(FCameraManager::GetInstance()->GetLookAtPosition());
	AddObject(IntroUserInterface, EObjectGroup::UserInterface);
	FResourceManager::GetInstance()->LoadSound(L"IntroBGM", L"Sound\\IntroBGM.wav", true);
	FResourceManager::GetInstance()->PlaySoundByKey(L"IntroBGM");
}

void FStartScene::Release() {
	FResourceManager::GetInstance()->StopChannel(ESoundChannel::BackgroundMusic);
}

void FStartScene::Render(HDC DeviceContext) {
	FScene::Render(DeviceContext);
	IntroUserInterface->Render(DeviceContext);
}

void FStartScene::Update() {
	FScene::Update();
	IntroUserInterface->Update();
}
