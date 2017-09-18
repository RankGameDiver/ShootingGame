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

	m_pPlayer = new CPlayerInfo();
	m_pPlayer->Initialize();
	m_pPlayer->Load("./Images/ÁÖÀÎ°ø.png");
	g_pInputManager->SetInputHandler(m_pPlayer);

	m_eEnemy = new CEnemy();
	m_eEnemy->Initialize(eEnemyKind_Banana);

	return true;
}

void CInGame::Terminate()
{
	m_pPlayer->Terminate();
	m_eEnemy->Terminate();
	CBaseRender::Terminate();
}

bool CInGame::Pulse()
{
	CBaseRender::Pulse();
	
	m_pPlayer->Pulse();
	m_eEnemy->Pulse();

	return true;
}

void CInGame::Render()
{
	CBaseRender::Render();
	m_pPlayer->Render();
	m_eEnemy->Render();
}
