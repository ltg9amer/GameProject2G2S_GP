#include "pch.h"
#include "FoodButton.h"
#include "Texture.h"
#include "ResMgr.h"

FoodButton::FoodButton()
{
	texture = ResMgr::GetInst()->TexLoad(L"LeftArrowButton", L"Texture\\LeftArrow.bmp");
	m_vScale = Vec2(41.5f, 64.f);
}

FoodButton::~FoodButton()
{
}

void FoodButton::Update()
{
	Button::Update();
}

void FoodButton::Render(HDC _dc)
{
	Button::Render(_dc);
}
