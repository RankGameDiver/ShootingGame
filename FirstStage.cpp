#include "stdafx.h"

POINT pt;
CFirstStage::CFirstStage(void)
{
}

CFirstStage::~CFirstStage(void)
{
}

bool CFirstStage::Initialize()
{
	CInGame::Initialize();

	m_pBackGroundA = new CBackGround();
	m_pBackGroundA->Initialize(35,0);
	m_pBackGroundA->Load("./Images/인게임배경1.png");

	m_pBackGroundB = new CBackGround();
	m_pBackGroundB->Initialize(35,-3000);
	m_pBackGroundB->Load("./Images/인게임배경1.png");

	m_pBackGround2 = new CBackGround();
	m_pBackGround2->Initialize(0);
	m_pBackGround2->Load("./Images/게임UI/17_슈팅게임_in game_1스테이지.png");

	m_pPlayer = new CPlayerInfo();
	m_pPlayer->Initialize();
	m_pPlayer->Load("./Images/주인공.png");
	g_pInputManager->SetInputHandler(m_pPlayer);

	m_pEnemyManager = new CEnemyManager;
	m_pEnemyManager->Initialize(m_pPlayer);
	m_pEnemyManager->OnObject(5)->Initialize(Vector2D(100, 100), m_pPlayer); // OnObject의 인자는 몬스터의 종류
	m_pEnemyManager->OnObject(1)->Initialize(Vector2D(200, 100), m_pPlayer);
	m_pEnemyManager->OnObject(2)->Initialize(Vector2D(400, 100), m_pPlayer);

	return true;
}

void CFirstStage::Terminate()
{
	CInGame::Terminate();
}

//버튼을 하려고 했는데 미안하다...
bool CFirstStage::Pulse()
{
	CInGame::Pulse();
	RECT rc{ 0,100,200,200 };

	if (PtInRect(&rc,pt))
	{
		if (m_bIsMouseLeft)
		{
			g_pSystem->ChangeScene(IScene::eSceneType_Stage2);
		}
	}
	
	if (m_pBackGroundA->m_vPos.y >= 3000)
		m_pBackGroundA->m_vPos.y = -3000;
	m_pBackGroundA->m_vPos.y += 5;
	if (m_pBackGroundB->m_vPos.y >= 3000)
		m_pBackGroundB->m_vPos.y = -3000;
	m_pBackGroundB->m_vPos.y += 5;

	return true;
}

void CFirstStage::Render()
{
	CInGame::Render();
}

void CFirstStage::KeyboardHandler()
{

}

void CFirstStage::MouseHandler(MOUSESTATE diMouseState)
{
	m_bIsMouseLeft = (diMouseState.btn[0]) ? true : false;
	m_bIsMouseRight = (diMouseState.btn[1]) ? true : false;
}