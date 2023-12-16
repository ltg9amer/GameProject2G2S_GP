#include "pch.h"
#include "ExitButton.h"
#include "ResMgr.h"
#include "Texture.h"

ExitButton::ExitButton()
{
	texture = ResMgr::GetInst()->TexLoad(L"ExitButton", L"Texture\\ExitButton.bmp");
	m_vScale = Vec2(texture->GetWidth() / 3.f * 2.f, texture->GetHeight() / 3.f * 2.f);
}

ExitButton::~ExitButton()
{
}

void ExitButton::Update()
{
	Button::Update();
}

void ExitButton::Render(HDC _dc)
{
	Button::Render(_dc);
}

void ExitButton::OnButtonClick()
{
	std::exit(1);
}
