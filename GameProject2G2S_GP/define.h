#pragma once
#define DELTA_TIME FTimeManager::GetInstance()->GetDeltaTime()
#define ELLIPSE_RENDER(PosX, PosY, ScaleX, ScaleY, DeviceContext) Ellipse(DeviceContext, int(PosX - ScaleX * 0.5f), int(PosY - ScaleY * 0.5f), int(PosX + ScaleX * 0.5f), int(PosY + ScaleY * 0.5f))
#define KEY_CHECK(Key, State) FKeyManager::GetInstance()->GetKeyState(Key) == State
#define KEY_DOWN(Key) KEY_CHECK(Key, EKeyState::Down)
#define KEY_NONE(Key) KEY_CHECK(Key, EKeyState::None)
#define KEY_PRESS(Key) KEY_CHECK(Key, EKeyState::Press)
#define KEY_UP(Key) KEY_CHECK(Key, EKeyState::Up)
#define RECTANGLE_MAKE(PosX, PosY, ScaleX, ScaleY) { PosX - ScaleX * 0.5f, PosY - ScaleY * 0.5f, PosX + ScaleX * 0.5f, PosY + ScaleY * 0.5f}
#define RECTANGLE_RENDER(PosX, PosY, ScaleX, ScaleY, DeviceContext) Rectangle(DeviceContext, int(PosX - ScaleX * 0.5f), int(PosY - ScaleY * 0.5f), int(PosX + ScaleX * 0.5f), int(PosY + ScaleY * 0.5f))
#define SINGLETON(TType)\
public:\
	static TType* GetInstance() {\
		static TType Instance;\
\
		return &Instance;\
	}\
\
private:\
	TType() {\
\
	}\
\
	~TType() {\
\
	}
#define WINDOW_CLASS_NAME L"Parva"
#define WINDOW_HEIGHT 755
#define WINDOW_WIDTH 500
