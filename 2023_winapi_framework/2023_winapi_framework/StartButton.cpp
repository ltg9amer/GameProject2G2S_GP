#include "pch.h"
#include "ResMgr.h"
#include "StartButton.h"
#include "Texture.h"
#include "SceneMgr.h"

StartButton::StartButton()
{
	texture = ResMgr::GetInst()->TexLoad(L"StartButton", L"Texture\\StartButton.bmp");
	m_vScale = Vec2(texture->GetWidth(), texture->GetHeight());
}

StartButton::~StartButton()
{
}

void StartButton::Update()
{
	Button::Update();
}

void StartButton::Render(HDC _dc)
{
	Button::Render(_dc);
}

void StartButton::OnButtonClick()
{
	SceneMgr::GetInst()->LoadScene(L"PlayScene");
}
