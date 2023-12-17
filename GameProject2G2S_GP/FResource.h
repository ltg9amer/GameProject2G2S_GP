#pragma once

class FResource {
	wstring Key;
	wstring RelativePath;

public:
	FResource();

	~FResource();

	const wstring& GetKey() const {
		return Key;
	}

	const wstring& GetRelativePath() const {
		return RelativePath;
	}

	void SetKey(const wstring& Key) {
		this->Key = Key;
	}

	void SetRelativePath(const wstring& Path) {
		RelativePath = Path;
	}
};

