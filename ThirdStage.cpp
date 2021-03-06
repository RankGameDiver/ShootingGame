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
	m_pBackGroundA->Load("./Images/인게임배경3.png");

	m_pPlayer = new CPlayerInfo();
	m_pPlayer->Initialize();
	m_pPlayer->Load("./Images/주인공.png");
	g_pInputManager->SetInputHandler(m_pPlayer);

	m_pEnemyManager = new CEnemyManager;
	m_pEnemyManager->Initialize(m_pPlayer);
	m_pEnemyManager->OnObject(1)->Initialize(Vector2D(100, 100), m_pPlayer); // 첫번째 인자는 몬스터 종류

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
