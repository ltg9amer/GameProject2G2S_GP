#include "pch.h"
#include "Button.h"
#include "CameraManager.h"
#include "EventMgr.h"
#include "KeyMgr.h"
#include "Texture.h"

Button::Button() : isPressed(false)
{

}

Button::~Button()
{
}

void Button::Update()
{
	UIElement::Update();

	if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
		Vec2 mousePosition = KeyMgr::GetInst()->GetMousePos();

		if (mousePosition.x >= interactionRectangle.left && mousePosition.x <= interactionRectangle.right && mousePosition.y >= interactionRectangle.top && mousePosition.y <= interactionRectangle.bottom) {
			isPressed = true;
		}
	}

	if (isPressed && KEY_UP(KEY_TYPE::LBUTTON)) {
		Vec2 mousePosition = KeyMgr::GetInst()->GetMousePos();

		if (mousePosition.x >= interactionRectangle.left && mousePosition.x <= interactionRectangle.right && mousePosition.y >= interactionRectangle.top && mousePosition.y <= interactionRectangle.bottom) {
			EventMgr::GetInst()->ClickButton(this);
		}

		isPressed = false;
	}
}

void Button::Render(HDC _dc)
{
	long width = texture->GetWidth(), height = texture->GetHeight();

	if (isPressed) {
		TransparentBlt(_dc, interactionRectangle.left + m_vScale.x *.1f, interactionRectangle.top + m_vScale.y * .1f, m_vScale.x * .8f, m_vScale.y * .8f, texture->GetDC(), 0, 0, width, height, RGB(255, 0, 255));
	}
	else {
		TransparentBlt(_dc, interactionRectangle.left, interactionRectangle.top, m_vScale.x, m_vScale.y, texture->GetDC(), 0, 0, width, height, RGB(255, 0, 255));
	}

	UIElement::Render(_dc);
}
