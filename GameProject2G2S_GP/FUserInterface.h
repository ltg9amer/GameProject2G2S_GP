#pragma once
#include "FObject.h"

class FScene;

class FUserInterfaceElement;

class FUserInterface : public FObject {
	vector<FUserInterfaceElement*> Elements[(UINT)EUserInterfaceElementGroup::Last];
	FScene* OwnerScene;

public:
	FUserInterface();

	virtual ~FUserInterface();

	const FScene* GetOwnerScene() const {
		return OwnerScene;
	}

	virtual void Initialize() abstract;

	virtual void Release();

	virtual void Render(HDC _dc) override;

	virtual void Update() override;

	vector<FUserInterfaceElement*> GetElementsOfGroup(EUserInterfaceElementGroup ElementGroup) {
		return Elements[(UINT)ElementGroup];
	}

	void AddElement(FUserInterfaceElement* Element, EUserInterfaceElementGroup ElementGroup) {
		Elements[(UINT)ElementGroup].push_back(Element);
	}

	void SetOwnerScene(FScene* Scene) {
		OwnerScene = Scene;
	}
};

