#include "pch.h"
#include "BananaButton.h"
#include "Texture.h"
#include "ResMgr.h"

BananaButton::BananaButton()
{
	texture = ResMgr::GetInst()->TexLoad(L"Banana", L"Texture\\Banana.bmp");
	m_vScale = Vec2(41.5f, 64.f);
}

BananaButton::~BananaButton()
{
}

void BananaButton::Update()
{
	Button::Update();
}

void BananaButton::Render(HDC _dc)
{
	Button::Render(_dc);
}

void BananaButton::OnButtonClick()
{
	ownerFood.Purchase();
}
