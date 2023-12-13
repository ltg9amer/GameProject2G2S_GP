#include "pch.h"
#include "Background.h"
#include "CameraManager.h"
#include "ResMgr.h"
#include "Texture.h"

Background::Background() : currentScene((UINT)SceneType::Kitchen), texture(nullptr), cameraPositionByScene{ Vec2(-500.f, 0.f), Vec2(0.f, 0.f), Vec2(500.f, 0.f) }
{
	texture = ResMgr::GetInst()->TexLoad(L"Background", L"Texture\\Background.bmp");

	SetScale(Vec2((int)texture->GetWidth(), (int)texture->GetHeight()));
}

Background::~Background()
{
}

void Background::Update()
{
}

void Background::Render(HDC _dc)
{
	Vec2 renderPosition = CameraManager::GetInst()->GetRenderPosition(GetPos());
	Vec2 scale = GetScale();

	BitBlt(_dc
		, (int)(renderPosition.x - scale.x / 2)
		, (int)(renderPosition.y - scale.y / 2)
		, texture->GetWidth(), texture->GetHeight(), texture->GetDC()
		, 0, 0, SRCCOPY);
}
