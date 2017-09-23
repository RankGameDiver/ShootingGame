#include "stdafx.h"

CFirstStage::CFirstStage(void)
{
}

CFirstStage::~CFirstStage(void)
{
}

bool CFirstStage::Initialize()
{
	CInGame::Initialize();

	m_pBackGround = new CBackGround();
	m_pBackGround->Initialize();
	m_pBackGround->Load("./Images/�ΰ��ӹ��1.png");

	m_pPlayer = new CPlayerInfo();
	m_pPlayer->Initialize();
	m_pPlayer->Load("./Images/���ΰ�.png");
	g_pInputManager->SetInputHandler(m_pPlayer);

	m_pEnemyManager = new CEnemyManager;
	m_pEnemyManager->Initialize(0, Vector2D(100, 100));
	m_pEnemyManager->OnObject()->Initialize(0, Vector2D(100, 100));

	return true;
}

void CFirstStage::Terminate()
{
	CInGame::Terminate();
}

bool CFirstStage::Pulse()
{
	CInGame::Pulse();
	return true;
}

void CFirstStage::Render()
{
	CInGame::Render();
}
