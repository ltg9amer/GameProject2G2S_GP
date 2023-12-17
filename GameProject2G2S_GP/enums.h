#pragma once

enum class EBrushType {
	Hollow,
	Red,
	Green,
	Blue,
	Yellow,
	Last
};

enum class EEventType {
	DeleteObject,
	CreateObject,
	SceneChange,
	ButtonClick,
	Last
};

enum class EKeyState {
	None,
	Down,
	Press,
	Up
};

enum class EKeyType {
	Left,
	Right,
	Up,
	Down,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,
	Z,
	X,
	C,
	V,
	B,
	N,
	M,
	Control,
	LeftAlt,
	LeftShift,
	Space,
	Enter,
	Tab,
	Escape,
	LeftMouseButton,
	RightMouseButton,
	Last
};

enum class EObjectGroup {
	Default,
	Background,
	Character,
	UserInterface,
	Last = 30
};

enum class EPenType {
	Hollow,
	Red,
	Green,
	Blue,
	Yellow,
	Last

};

enum class ERoomType {
	Bedroom,
	Kitchen,
	Playroom,
	Last

};

enum class EUserInterfaceElementGroup {
	Image,
	Text,
	Button,
	Last
};