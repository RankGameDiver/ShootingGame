#include "stdafx.h"

CInGame::CInGame(void)
{
	m_fTime = 0.0f;
}

CInGame::~CInGame(void)
{
}

bool CInGame::Initialize()
{
	if (!CBaseRender::Initialize())
	{
		return false;
	}

	m_pBackGround = new CBackGround();
	m_pBackGround->Initialize();
	m_pBackGround->Load("./Images/인게임배경1.png");

	m_pPlayer = new CPlayerInfo();
	m_pPlayer->Initialize();
	m_pPlayer->Load("./Images/주인공.png");
	g_pInputManager->SetInputHandler(m_pPlayer);

	m_pEnemy = new CEnemy();
	m_pEnemy->Initialize(eEnemyKind_Banana);
	m_pEnemy->Load("./Images/바나나.png");

	return true;
}

void CInGame::Terminate()
{
	m_pBackGround->Terminate();
	m_pPlayer->Terminate();
	m_pEnemy->Terminate();
	CBaseRender::Terminate();
}

bool CInGame::Pulse()
{
	CBaseRender::Pulse();
	
	m_pBackGround->Pulse();
	m_pPlayer->Pulse();
	m_pEnemy->Pulse();

	return true;
}

void CInGame::Render()
{
	CBaseRender::Render();
	m_pBackGround->Render();
	m_pPlayer->Render();
	m_pEnemy->Render();
}
