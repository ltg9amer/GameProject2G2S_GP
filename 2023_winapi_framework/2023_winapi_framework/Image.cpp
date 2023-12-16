#include "pch.h"
#include "CameraManager.h"
#include "Image.h"
#include "ResMgr.h"
#include "Texture.h"

Image::Image(wstring imageName, float scaleMultiflier)
{
	texture = ResMgr::GetInst()->TexLoad(imageName, L"Texture\\" + imageName + L".bmp");
	m_vScale = Vec2(texture->GetWidth() * scaleMultiflier, texture->GetHeight() * scaleMultiflier);
}

Image::~Image()
{
}

void Image::Update()
{
	UIElement::Update();
}

void Image::Render(HDC _dc)
{
	Vec2 renderPosition = CameraManager::GetInst()->GetRenderPosition(m_vPos);

	TransparentBlt(_dc, renderPosition.x - m_vScale.x * .5f, renderPosition.y - m_vScale.y * .5f, m_vScale.x, m_vScale.y, texture->GetDC(), 0, 0, texture->GetWidth(), texture->GetHeight(), RGB(255, 0, 255));

	UIElement::Render(_dc);
}
