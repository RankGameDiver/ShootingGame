#include "stdafx.h"
#include "GameMenu.h"

CGameMenu::CGameMenu(void)
{

}
CGameMenu::~CGameMenu(void)
{
}

bool CGameMenu::Initialize()
{
	CInGame::Initialize();

	m_pBackGround = new CBackGround();
	m_pBackGround->Initialize();
	m_pBackGround->Load("./Images/Menu.png");

	RECT rc = { 0, 200, 755, 405 };
	if (PtInRect, &rc)
	{
		g_pSystem->ChangeScene(IScene::eSceneType_Stage1);
	}

	return true;
}

void CGameMenu::Terminate()
{
	CInGame::Terminate();
}

bool CGameMenu::Pulse()
{

	CInGame::Pulse();
	return true;
}

void CGameMenu::Render()
{
	CInGame::Render();
}