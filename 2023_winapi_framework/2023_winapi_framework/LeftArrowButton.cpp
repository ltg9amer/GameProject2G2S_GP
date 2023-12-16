#include "pch.h"
#include "LeftArrowButton.h"
#include "PlayScene.h"
#include "ResMgr.h"
#include "Texture.h"
#include "UI.h"

LeftArrowButton::LeftArrowButton()
{
	texture = ResMgr::GetInst()->TexLoad(L"LeftArrowButton", L"Texture\\LeftArrow.bmp");
	m_vScale = Vec2(texture->GetWidth() / 3.f, texture->GetHeight() / 3.f);
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

void LeftArrowButton::OnButtonClick()
{
	((PlayScene*)ownerUI->GetOwnerScene())->MoveLeftRoom();
}
