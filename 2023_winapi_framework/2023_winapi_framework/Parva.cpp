#include "pch.h"
#include "Parva.h"
#include "ResMgr.h"
#include "Texture.h"

Parva::Parva()
{
	texture = ResMgr::GetInst()->TexLoad(L"Parva", L"Texture\\Parva.bmp");
	m_vScale = Vec2(texture->GetWidth() * .75f, texture->GetHeight() * .75f);
}

Parva::~Parva()
{
}

void Parva::Update()
{
}

void Parva::Render(HDC _hdc)
{
}
