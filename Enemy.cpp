#include "stdafx.h"

CEnemy::CEnemy()
{
	m_eRenderType = eRenderType_Enemy;

	m_bIsActive = false;

	m_nLife = MAX_ENEMY_LIFE;
	move = true; 
}

CEnemy::~CEnemy()
{
}

bool CEnemy::Initialize(int m_eEnemyKind, Vector2D pos)
{
	CBaseRender::Initialize();
	CTimeManager::Initialize();

	bulletList = new CBulletManager;
	bulletList->Init();

	switch (m_eEnemyKind)
	{
	case 0: // 바나나
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 80);
		}
		CBaseRender::Load("./Images/바나나.png");
		break;
	case 1: // 오너
		m_pImageInfo = new CImageInfo[5];
		for (int i = 0; i < 5; i++)
		{
			m_pImageInfo[i].SetRect(i * 96, 0, 96, 76);
		}
		CBaseRender::Load("./Images/오너.png");
		break;
	case 2: // 토끼
		m_pImageInfo = new CImageInfo[8];
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		CBaseRender::Load("./Images/토끼.png");
		break;
	case 3: // 인형
		m_pImageInfo = new CImageInfo[8];
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		CBaseRender::Load("./Images/인형.png");
		break;
	case 4: // 콩
		m_pImageInfo = new CImageInfo[8];
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * 96, 0, 96, 76);
		}
		CBaseRender::Load("./Images/콩.png");
		break;
	case 5: // 호두까기
		m_pImageInfo = new CImageInfo[8];
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		CBaseRender::Load("./Images/호두까기.png");
		break;
	case 6: // 강아지
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		CBaseRender::Load("./Images/강아지.png");
		break;
	case 7: // 보라색
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 96, 0, 96, 76);
		}
		CBaseRender::Load("./Images/보라색.png");
		break;
	case 8: // 호박
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		CBaseRender::Load("./Images/호박.png");
		break;
	default:
		break;
	}

	m_vPos.x = pos.x;
	m_vPos.y = pos.y;

	m_pGameFrame = new CFrameSkip();

	CBaseObject::SetUpCollision();
	return true;
}

void CEnemy::Terminate()
{
	delete[] this;
	delete bulletList;
}

bool CEnemy::Pulse()
{

	CTimeManager::Pulse();
	bulletList->Frame(1);

	// 애니메이션 프레임 속도 조절
	float fTimeStep = CTimeManager::GetTimeStep();
	if (m_pGameFrame->Update(fTimeStep))
	{
		static unsigned int frame = 0;
		static float deltaTime = 0;

		if (frame > 5)
		{
			frame = 0;
			//bulletList->OnObject()->Initialize(1, Vector2D(m_vPos.x, m_vPos.y));
		}

		m_kImageInfo = m_pImageInfo[frame];
		if (deltaTime >= 0.12f)
		{
			frame++;
			deltaTime = 0;
		}
		deltaTime += fTimeStep;
	}

	if (move)
	{
		m_vPos.x += 1;
		if (m_vPos.x >= 400)
		{
			move = false;
		}
	}
	else
	{
		m_vPos.x -= 1;
		if (m_vPos.x <= 10)
		{
			move = true;
		}
	}

	CBaseObject::Pulse();

	if (m_nLife <= 0)
	{
		m_bIsActive = false;
	}

	return true;
}

void CEnemy::Render()
{
	POINT ptPosText;

	ptPosText.x = m_vPos.x;
	ptPosText.y = m_vPos.y;

	g_pGraphicManager->DrawTextFormat(m_vPos.x, m_vPos.y, 0xFFFF0000, "(%d,%d)", ptPosText.x, ptPosText.y);

	CBaseRender::RenderSet(m_vPos);
	CBaseObject::Render(mat);
	bulletList->Render();
}