#include "pch.h"
#include "FCore.h"
#include "FKeyManager.h"

void FKeyManager::Initialize() {
	for (int i = 0; i < (UINT)EKeyType::Last; ++i) {
		KeyInformations.push_back(FKeyInformation{ EKeyState::None, false });
	}
}

void FKeyManager::Update() {
	HWND Window = GetFocus();

	if (Window != nullptr) {
		for (int i = 0; i < (UINT)EKeyType::Last; ++i) {
			if (GetAsyncKeyState(VirtualKeyList[i])) {
				if (KeyInformations[i].bIsClickedBefore) {
					KeyInformations[i].State = EKeyState::Press;
				}
				else {
					KeyInformations[i].State = EKeyState::Down;
				}

				KeyInformations[i].bIsClickedBefore = true;
			}
			else {
				if (KeyInformations[i].bIsClickedBefore) {
					KeyInformations[i].State = EKeyState::Up;
				}
				else {
					KeyInformations[i].State = EKeyState::None;
				}

				KeyInformations[i].bIsClickedBefore = false;
			}
		}

		GetCursorPos(&MousePosition);
		ScreenToClient(FCore::GetInstance()->GetWindow(), &MousePosition);
	}
	else {
		for (int i = 0; i < (UINT)EKeyType::Last; ++i) {
			KeyInformations[i].bIsClickedBefore = false;

			if (KeyInformations[i].State == EKeyState::Press || KeyInformations[i].State == EKeyState::Down) {
				KeyInformations[i].State = EKeyState::Up;
			}

			if (KeyInformations[i].State == EKeyState::Up) {
				KeyInformations[i].State = EKeyState::None;
			}
		}
	}
}
