#include "pch.h"
#include "FPlayScene.h"
#include "FSceneManager.h"
#include "FStartScene.h"

void FSceneManager::Initialize() {
	CurrentScene = nullptr;

	RegisterScene(L"StartScene", std::make_shared<FStartScene>());
	RegisterScene(L"PlayScene", std::make_shared<FPlayScene>());
	LoadScene(L"StartScene");
}

void FSceneManager::LoadScene(const wstring& Name) {
	if (CurrentScene != nullptr) {
		CurrentScene->Release();

		CurrentScene = nullptr;
	}

	auto Iterator = Scenes.find(Name);

	if (Iterator != Scenes.end()) {
		CurrentScene = Iterator->second;

		CurrentScene->Initialize();
	}
}

void FSceneManager::Update() {
	CurrentScene->Update();
	CurrentScene->FinalUpdate();
}

void FSceneManager::RegisterScene(const wstring& Name, std::shared_ptr<FScene> Scene) {
	Scenes.insert(Scenes.end(), { Name, Scene });
}

void FSceneManager::Render(HDC DeviceContext) {
	CurrentScene->Render(DeviceContext);
}
