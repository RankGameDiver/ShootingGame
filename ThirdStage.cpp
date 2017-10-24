#include "stdafx.h"

CThirdStage::CThirdStage(void)
{
}

CThirdStage::~CThirdStage(void)
{
}

bool CThirdStage::Initialize()
{
	CInGame::Initialize();

	m_pBackGroundA = new CBackGround();
	m_pBackGroundA->Initialize(0);
	m_pBackGroundA->Load("./Images/�ΰ��ӹ��3.png");

	m_pPlayer = new CPlayerInfo();
	m_pPlayer->Initialize();
	m_pPlayer->Load("./Images/���ΰ�.png");
	g_pInputManager->SetInputHandler(m_pPlayer);

	m_pEnemyManager = new CEnemyManager;
	m_pEnemyManager->Initialize(m_pPlayer);
	m_pEnemyManager->OnObject(1)->Initialize(Vector2D(100, 100), m_pPlayer); // ù��° ���ڴ� ���� ����

	return true;
}

void CThirdStage::Terminate()
{
	CInGame::Terminate();
}

bool CThirdStage::Pulse()
{
	CInGame::Pulse();
	return true;
}

void CThirdStage::Render()
{
	CInGame::Render();
}