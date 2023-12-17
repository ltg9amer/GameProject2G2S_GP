#pragma once
#include "define.h"

struct FKeyInformation {
	EKeyState State;
	bool bIsClickedBefore;
};

class FKeyManager {
	SINGLETON(FKeyManager);

	vector<FKeyInformation> KeyInformations;
	int VirtualKeyList[(UINT)EKeyType::Last] = { VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', VK_CONTROL, VK_LMENU, VK_LSHIFT, VK_SPACE,	VK_RETURN, VK_TAB, VK_ESCAPE, VK_LBUTTON, VK_RBUTTON };
	POINT MousePosition;

public:
	const EKeyState& GetKeyState(EKeyType Key) const {
		return KeyInformations[(UINT)Key].State;
	}

	const POINT& GetMousePosition() const {
		return MousePosition;
	}

	void Initialize();

	void Update();
};

