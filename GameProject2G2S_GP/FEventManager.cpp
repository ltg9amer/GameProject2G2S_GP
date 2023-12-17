#include "pch.h"
#include "FButton.h"
#include "FEventManager.h"
#include "FObject.h"

void FEventManager::ClickButton(FButton* ClickedButton) {
	FEvent Event;

	Event.Type = EEventType::ButtonClick;
	Event.Button = ClickedButton;

	Events.push_back(Event);
}

void FEventManager::DeleteObject(FObject* DeletingObject) {
	FEvent Event;

	Event.Type = EEventType::DeleteObject;
	Event.Object = DeletingObject;

	Events.push_back(Event);
}

void FEventManager::Update() {
	for (size_t i = 0; i < DeadObjects.size(); ++i) {
		delete DeadObjects[i];
	}

	DeadObjects.clear();

	for (size_t i = 0; i < Events.size(); ++i) {
		Excute(Events[i]);
	}

	Events.clear();
}

void FEventManager::Excute(const FEvent& Event) {
	switch (Event.Type) {
	case EEventType::DeleteObject: {
		FObject* DeletingObject = Event.Object;

		DeletingObject->SetDead();
		DeadObjects.push_back(DeletingObject);
	}

								 break;

	case EEventType::CreateObject:
		break;

	case EEventType::SceneChange:
		break;

	case EEventType::ButtonClick: {
		Event.Button->OnButtonClick();
	}

								break;
	}
}
