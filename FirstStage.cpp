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

	m_pBackGround = new CBackGround();
	m_pBackGround->Initialize();
	m_pBackGround->Load("./Images/인게임배경1.png");

	m_pPlayer = new CPlayerInfo();
	m_pPlayer->Initialize();
	m_pPlayer->Load("./Images/주인공.png");
	g_pInputManager->SetInputHandler(m_pPlayer);

	m_pEnemyManager = new CEnemyManager;
	m_pEnemyManager->Initialize(m_pPlayer);
	m_pEnemyManager->OnObject(2)->Initialize(Vector2D(100, 100), m_pPlayer); // OnObject의 인자는 몬스터의 종류

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