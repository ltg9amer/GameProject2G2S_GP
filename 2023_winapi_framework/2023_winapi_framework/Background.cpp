#include "pch.h"
#include "Background.h"
#include "CameraManager.h"
#include "Core.h"
#include "ResMgr.h"
#include "Texture.h"

Background::Background() : texture(nullptr), cameraPositionsByRoom{ Vec2(-250.f, Core::GetInst()->GetResolution().y * .5f), Vec2(250.f, Core::GetInst()->GetResolution().y * .5f), Vec2(750.f, Core::GetInst()->GetResolution().y * .5f)}
{
	texture = ResMgr::GetInst()->TexLoad(L"Background", L"Texture\\Background.bmp");
	m_vScale = Vec2(texture->GetWidth(), texture->GetHeight());
}

Background::~Background()
{
}

void Background::Update()
{
}

void Background::Render(HDC _dc)
{
	Vec2 renderPosition = CameraManager::GetInst()->GetRenderPosition(m_vPos);

	BitBlt(_dc
		, (int)(renderPosition.x - m_vScale.x / 2)
		, (int)(renderPosition.y - m_vScale.y / 2)
		, texture->GetWidth(), texture->GetHeight(), texture->GetDC()
		, 0, 0, SRCCOPY);
}
