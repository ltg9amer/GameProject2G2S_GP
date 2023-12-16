#include "pch.h"
#include "StartScene.h"
#include "Object.h"
#include "Core.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "ResMgr.h"
#include "Texture.h"

void StartScene::Init()
{
	IntroBackground = ResMgr::GetInst()->TexLoad(L"IntroImage", L"Texture\\ParvaIntro.bmp");

	ResMgr::GetInst()->LoadSound(L"IntroBGM", L"Sound\\IntroBGM.wav", true);
	ResMgr::GetInst()->Play(L"IntroBGM");
}

void StartScene::Render(HDC _dc)
{
	int x = 10;//Core::GetInst()->GetResolution().x / 2 - 75 ;
	int y = Core::GetInst()->GetResolution().y / 2 + 150;

	TransparentBlt(_dc, -100, 0, 1500, 754, IntroBackground->GetDC(), 0, 0, IntroBackground->GetWidth(), IntroBackground->GetHeight(), RGB(255, 0, 255));
}

void StartScene::Update()
{
	Scene::Update();

	Vec2 mousePos = KeyMgr::GetInst()->GetMousePos();

	if (mousePos.x >= 555 && mousePos.x <= 855 && mousePos.y >= 550 && mousePos.y <= 755)
	{
		if (KEY_PRESS(KEY_TYPE::LBUTTON))
		{
			//³ª°¡±â
			std::exit(1);
		}
	}

	if (mousePos.x >= 495 && mousePos.x <= 895 && mousePos.y >= 350 && mousePos.y <= 500)
	{
		if (KEY_PRESS(KEY_TYPE::LBUTTON))
		{
			SceneMgr::GetInst()->LoadScene(L"Game_Scene");
		}
	}
}

void StartScene::Release()
{
	ResMgr::GetInst()->Stop(SOUND_CHANNEL::BGM);
}

void StartScene::FinalUpdate()
{
}
