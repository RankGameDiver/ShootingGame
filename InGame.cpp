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
	m_pBackGroundA->Terminate();
	m_pBackGroundB->Terminate();
	m_pBackGround2->Terminate();
	m_pPlayer->Terminate();
	m_pEnemyManager->Terminate();
	CBaseRender::Terminate();
}

bool CInGame::Pulse()
{
	CBaseRender::Pulse();
	m_pBackGroundA->Pulse();
	m_pBackGroundB->Pulse();
	m_pBackGround2->Pulse();
	m_pPlayer->Pulse();
	m_pEnemyManager->Pulse();
	return true;
}

void CInGame::Render()
{
	CBaseRender::Render();
	m_pBackGroundA->Render();
	m_pBackGroundB->Render();
	m_pBackGround2->Render();
	m_pPlayer->Render();
	m_pEnemyManager->Render();
}
