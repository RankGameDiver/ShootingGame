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
	return true;
}

void CInGame::Terminate()
{
	m_pBackGround->Terminate();
	m_pPlayerManager->Terminate();
	m_pEnemyManager->Terminate();
	CBaseRender::Terminate();
}

bool CInGame::Pulse()
{
	CBaseRender::Pulse();
	m_pBackGround->Pulse();
	m_pPlayerManager->Pulse();
	m_pEnemyManager->Pulse();
	return true;
}

void CInGame::Render()
{
	CBaseRender::Render();
	m_pBackGround->Render();
	m_pPlayerManager->Render();
	m_pEnemyManager->Render();
}
