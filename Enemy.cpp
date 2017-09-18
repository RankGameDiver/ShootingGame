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
	CBaseObject::Initialize();

	switch (m_eEnemyKind)
	{
	case 0: // 바나나
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo = new CImageInfo[6];
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 80);
		}
		break;
	case 1: // 오너
		for (int i = 0; i < 5; i++)
		{
			m_pImageInfo = new CImageInfo[5];
			m_pImageInfo[i].SetRect(i * 96, 0, 96, 76);
		}
		break;
	case 2: // 토끼
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo = new CImageInfo[8];
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		break;
	case 3: // 인형
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo = new CImageInfo[8];
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		break;
	case 4: // 콩
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo = new CImageInfo[8];
			m_pImageInfo[i].SetRect(i * 96, 0, 96, 76);
		}
		break;
	case 5: // 호두까기
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo = new CImageInfo[8];
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		break;
	case 6: // 강아지
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo = new CImageInfo[6];
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		break;
	case 7: // 보라색
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo = new CImageInfo[6];
			m_pImageInfo[i].SetRect(i * 96, 0, 96, 76);
		}
		break;
	case 8: // 호박
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo = new CImageInfo[6];
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

	CBaseObject::SetUpCollision();
	CBaseRender::Load("./Images/바나나.png");
	return true;
}

void CEnemy::Terminate()
{

}

bool CEnemy::Pulse()
{
	float fOffset = 200 * g_pSystem->GetTimeStep();

	m_eActionState = eActionState::eActionState_Normal;

	m_kImageInfo = m_pImageInfo[0];

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
