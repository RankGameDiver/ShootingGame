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
