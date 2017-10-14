#include "stdafx.h"

CSecondStage ::CSecondStage(void)
{
}

CSecondStage ::~CSecondStage(void)
{
}

bool CSecondStage::Initialize()
{
	CInGame::Initialize();

	m_pBackGround = new CBackGround();
	m_pBackGround->Initialize();
	m_pBackGround->Load("./Images/�ΰ��ӹ��2.png");

	m_pPlayer = new CPlayerInfo();
	m_pPlayer->Initialize();
	m_pPlayer->Load("./Images/���ΰ�.png");
	g_pInputManager->SetInputHandler(m_pPlayer);

	m_pEnemyManager = new CEnemyManager;
	m_pEnemyManager->Initialize(m_pPlayer);
	m_pEnemyManager->OnObject(1)->Initialize(Vector2D(100, 100), m_pPlayer); // ù��° ���ڴ� ���� ����

	return true;
}

void CSecondStage::Terminate()
{
	CInGame::Terminate();
}

bool CSecondStage::Pulse()
{
	CInGame::Pulse();
	return true;
}

void CSecondStage::Render()
{
	CInGame::Render();
}
