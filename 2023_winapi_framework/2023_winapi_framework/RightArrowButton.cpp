#include "pch.h"
#include "PlayScene.h"
#include "ResMgr.h"
#include "RightArrowButton.h"
#include "Texture.h"
#include "UI.h"

RightArrowButton::RightArrowButton()
{
	texture = ResMgr::GetInst()->TexLoad(L"RightArrowButton", L"Texture\\RightArrow.bmp");
	m_vScale = Vec2(texture->GetWidth() / 3.f, texture->GetHeight() / 3.f);
}

RightArrowButton::~RightArrowButton()
{
}

void RightArrowButton::Update()
{
	Button::Update();
}

void RightArrowButton::Render(HDC _dc)
{
	Button::Render(_dc);
}

void RightArrowButton::OnButtonClick()
{
	((PlayScene*)ownerUI->GetOwnerScene())->MoveRightRoom();
}
