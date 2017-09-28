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

	frame = 0;
	deltaTime = 0;

	switch (m_eEnemyKind)
	{
	case 0: // �ٳ���
		m_pImageInfo = new CImageInfo[6];
		m_vWH.x = 56;
		m_vWH.y = 80;
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/�ٳ���.png");
		break;
	case 1: // ����
		m_pImageInfo = new CImageInfo[5];
		m_vWH.x = 96;
		m_vWH.y = 76;
		for (int i = 0; i < 5; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/����.png");
		break;
	case 2: // �䳢
		m_pImageInfo = new CImageInfo[8];
		m_vWH.x = 56;
		m_vWH.y = 76;
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/�䳢.png");
		break;
	case 3: // ����
		m_pImageInfo = new CImageInfo[8];
		m_vWH.x = 56;
		m_vWH.y = 76;
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/����.png");
		break;
	case 4: // ��
		m_pImageInfo = new CImageInfo[8];
		m_vWH.x = 96;
		m_vWH.y = 76;
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/��.png");
		break;
	case 5: // ȣ�α��
		m_pImageInfo = new CImageInfo[8];
		m_vWH.x = 56;
		m_vWH.y = 76;
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/ȣ�α��.png");
		break;
	case 6: // ������
		m_pImageInfo = new CImageInfo[6];
		m_vWH.x = 56;
		m_vWH.y = 76;
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/������.png");
		break;
	case 7: // �����
		m_pImageInfo = new CImageInfo[6];
		m_vWH.x = 96;
		m_vWH.y = 76;
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/�����.png");
		break;
	case 8: // ȣ��
		m_pImageInfo = new CImageInfo[6];
		m_vWH.x = 56;
		m_vWH.y = 76;
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/ȣ��.png");
		break;
	default:
		break;
	}

	m_vPos.x = pos.x;
	m_vPos.y = pos.y;

	CBaseObject::SetUpCollision(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);
	return true;
}

void CEnemy::Terminate()
{
	delete[] this;
}

bool CEnemy::Pulse()
{
	CTimeManager::Pulse();
	bulletList->Frame(1);

	// �ִϸ��̼� ������ �ӵ� ����
	float fTimeStep = CTimeManager::GetTimeStep();
	if (m_pGameFrame->Update(fTimeStep))
	{
		if (frame > 5)
		{
			frame = 0;
			bulletList->OnObject()->Initialize(1, Vector2D(m_vPos.x, m_vPos.y));
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

	CBaseObject::Pulse(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);

	if (m_nLife <= 0)
	{
		m_bIsActive = false;
	}

	return true;
}

void CEnemy::Render()
{
	if (GetActive())
	{
		POINT ptPosText;

		ptPosText.x = m_vPos.x;
		ptPosText.y = m_vPos.y;

		g_pGraphicManager->DrawTextFormat(m_vPos.x, m_vPos.y, 0xFFFF0000, "(%d,%d)", ptPosText.x, ptPosText.y);

		CBaseRender::RenderSet(m_vPos);
		CBaseObject::Render(mat);
		bulletList->Render();
	}
}