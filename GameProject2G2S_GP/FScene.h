#pragma once

class FObject;

class FScene {
	vector<FObject*> Objects[(UINT)EObjectGroup::Last];

public:
	FScene();

	virtual ~FScene();

	const vector<FObject*>& GetObjectsOfGroup(EObjectGroup ObjectGroup) const {
		return Objects[(UINT)ObjectGroup];
	}

	virtual void FinalUpdate();

	virtual void Initialize() abstract;

	virtual void Release();

	virtual void Render(HDC DeviceContext);

	virtual void Update();

	void AddObject(FObject* Object, EObjectGroup ObjectGroup) {
		Objects[(UINT)ObjectGroup].push_back(Object);
	}
};

