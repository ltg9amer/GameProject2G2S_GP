#include "pch.h"
#include "LeftArrowButton.h"
#include "ResMgr.h"
#include "Texture.h"

LeftArrowButton::LeftArrowButton()
{
	texture = ResMgr::GetInst()->TexLoad(L"LeftArrowButton", L"Texture\\LeftArrow.bmp");
	m_vScale = Vec2(41.5f, 64.f);
}

LeftArrowButton::~LeftArrowButton()
{
}

void LeftArrowButton::Update()
{
	Button::Update();
}

void LeftArrowButton::Render(HDC _dc)
{
	Button::Render(_dc);
}
