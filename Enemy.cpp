#include "stdafx.h"

CEnemy::CEnemy()
{
	m_eRenderType = eRenderType_Enemy;

	m_bIsActive = false;

	m_nLife = MAX_ENEMY_LIFE;
}

CEnemy::~CEnemy()
{
}

bool CEnemy::Initialize(eEnemyKind m_eEnemyKind)
{
	CBaseRender::Initialize();

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
		break;
	case 2: // 토끼
		m_pImageInfo = new CImageInfo[8];
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		break;
	case 3: // 인형
		m_pImageInfo = new CImageInfo[8];
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		break;
	case 4: // 콩
		m_pImageInfo = new CImageInfo[8];
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * 96, 0, 96, 76);
		}
		break;
	case 5: // 호두까기
		m_pImageInfo = new CImageInfo[8];
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		break;
	case 6: // 강아지
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		break;
	case 7: // 보라색
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 96, 0, 96, 76);
		}
		break;
	case 8: // 호박
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		break;
	default:
		break;
	}

	m_vOffset.x = -10.0f;
	m_vOffset.y = -10.0f;

	SetPos();
	SetScale();

	m_eActionState = eActionState_Normal;

	m_pGameFrame = new CFrameSkip();

	CBaseObject::SetUpCollision();
	return true;
}

void CEnemy::Terminate()
{

}

bool CEnemy::Pulse()
{
	CTimeManager::Pulse();

	float fOffset = 200 * g_pSystem->GetTimeStep();

	m_eActionState = eActionState::eActionState_Normal;

	float fTimeStep = CTimeManager::GetTimeStep();

	//// 애니메이션 프레임 속도 조절
	if (m_pGameFrame->Update(fTimeStep))
	{
		static unsigned int frame = 0;
		static float deltaTime = 0;

		if (frame > 5)
		{
			frame = 0;
		}

		m_kImageInfo = m_pImageInfo[frame];
		if (deltaTime >= 0.12f)
		{
			frame++;
			deltaTime = 0;
		}
		deltaTime += fTimeStep;
	}

	CBaseObject::Pulse();

	return true;
}

void CEnemy::Render()
{
	TCHAR buffer[128];
	POINT ptPosText;

	ptPosText.x = m_vPos.x;
	ptPosText.y = m_vPos.y;

	g_pGraphicManager->DrawTextFormat(m_vPos.x, m_vPos.y, 0xFFFF0000, "(%d,%d)", ptPosText.x, ptPosText.y);

	CBaseRender::RenderSet(m_vPos, m_vScale);

	CBaseObject::Render(mat);
}
