#pragma once

class FPathManager {
	SINGLETON(FPathManager);

public:
	const wchar_t* GetResourcesPath() const {
		return ResourcesPath;
	}

	void Initialize();

private:
	wchar_t ResourcesPath[255];
};

