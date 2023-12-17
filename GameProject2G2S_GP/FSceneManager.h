#pragma once

class FScene;

class FSceneManager {
	SINGLETON(FSceneManager);

	map<wstring, std::shared_ptr<FScene>> Scenes;
	std::shared_ptr<FScene> CurrentScene;

public:
	const std::shared_ptr<FScene>& GetCurrentScene() const {
		return CurrentScene;
	}

	void Initialize();

	void LoadScene(const wstring& Name);

	void RegisterScene(const wstring& Name, std::shared_ptr<FScene> Scene);

	void Render(HDC DeviceContext);

	void Update();
};