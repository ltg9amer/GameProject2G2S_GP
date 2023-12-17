#pragma once

class FButton;

class FObject;

struct FEvent {
	EEventType Type;
	EObjectGroup ObjectGroup;
	FButton* Button;
	FObject* Object;
};

class FEventManager {
	SINGLETON(FEventManager);

	vector<FEvent> Events;
	vector<FObject*> DeadObjects;

public:
	void ClickButton(FButton* ClickedButton);

	void DeleteObject(FObject* DeletedObject);

	void Update();

private:
	void Excute(const FEvent& Event);
};

