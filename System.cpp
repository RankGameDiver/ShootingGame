#include "stdafx.h"

CSystem::CSystem(void)
{
	m_bIsReady = false;
	m_pCurrScene = NULL;
}

CSystem::~CSystem(void)
{

}

bool CSystem::Initialize(void)
{
	CBaseWindow::Initialize();
	CTimeManager::Initialize();

	m_pGameFrame = new CFrameSkip;
	m_pGameFrame->SetFramePerSec(60);

	m_pGraphicManager = new CGraphicManager;
	m_pGraphicManager->Initialize();

	m_pTextureManager = new CTextureManager;
	m_pTextureManager->Initialize();

	m_pInputManager = new CInputManager;
	m_pInputManager->Initialize();

	m_pImageManager = new CImageManager;
	m_pImageManager->Initialize();

	ChangeScene(IScene::eSceneType_InGame);

	return true;
}

void CSystem::Update(void)
{
	CTimeManager::Pulse();
	m_pInputManager->Pulse();

	if (!m_pCurrScene){ return; }
	m_pCurrScene->Pulse();

	m_pGraphicManager->Pulse();

	float fTimeStep = CTimeManager::GetTimeStep();

	if (m_pGameFrame->Update(fTimeStep))
	{
//*
		m_pGraphicManager->PreRender();

		m_pCurrScene->Render();
#ifdef _DEBUG
		static unsigned int nCount = 0;
		TCHAR buffer[128];
#ifdef _UNICODE
		m_pGraphicManager->DrawTextFormat(10, 10, 0xFFFF0000, L"[FPS:%5d][Time:%5d]", (int)GetFPS(), (int)GetTime());
#else
		m_pGraphicManager->DrawTextFormat(10, 10, 0xFFFF0000, "[FPS:%5d][Time:%5d]", (int)GetFPS(), (int)GetTime());
#endif
		nCount++;
#endif
		m_pGraphicManager->PostRender();
//*/
		}
}

void CSystem::Terminate(void)
{
	CBaseWindow::Terminate();
	CTimeManager::Terminate();

	m_pTextureManager->Terminate();
	delete m_pTextureManager;

	m_pGraphicManager->Terminate();
	delete m_pGraphicManager;

	g_pInputManager->SetInputHandler(NULL);

	delete m_pInputManager;
	delete m_pImageManager;
	delete m_pGameFrame;
}

void CSystem::Run(void)
{
	MSG msg;

	PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else	return;

		}
		else if (m_bIsActive)
		{
			Update();
		}
		else
		{
			WaitMessage();
		}
	}
}

void CSystem::ChangeScene(IScene::eSceneType eType)
{
	if (m_pCurrScene)
	{
		m_pCurrScene->Terminate();
		delete m_pCurrScene;
		m_pCurrScene = NULL;
	}

	switch (eType)
	{
	case IScene::eSceneType_Intro:
		m_pCurrScene = new CIntro;
		break;

	case IScene::eSceneType_Menu:
		m_pCurrScene = new CMenu;
		break;

	case IScene::eSceneType_InGame:
		m_pCurrScene = new CInGame;
		break;

	case IScene::eSceneType_Exit:
		break;

	case IScene::eSceneType_Quit:
		SendMessage(m_hWnd, WM_QUIT, NULL, NULL);
		break;
	}

	if (m_pCurrScene)
	{
		m_pCurrScene->Initialize();
	}

}