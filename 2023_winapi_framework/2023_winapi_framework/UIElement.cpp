#include "pch.h"
#include "CameraManager.h"
#include "UIElement.h"

UIElement::UIElement() : interactionRectangle{ 0, 0, 0, 0 }, texture(nullptr)
{
}

UIElement::~UIElement()
{
}

void UIElement::Update()
{
	Vec2 cameraPosition = CameraManager::GetInst()->GetLookAtPosition();

	m_vPos = cameraPosition + anchoredPosition;

	Vec2 renderPosition = CameraManager::GetInst()->GetRenderPosition(m_vPos);
	interactionRectangle = { long(renderPosition.x - m_vScale.x * .5f), long(renderPosition.y - m_vScale.y * .5f), long(renderPosition.x + m_vScale.x * .5f), long(renderPosition.y + m_vScale.y * .5f) };
}

void UIElement::Render(HDC _dc)
{
	Component_Render(_dc);
}
