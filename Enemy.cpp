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
	case 0: // �ٳ���
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 80);
		}
		CBaseRender::Load("./Images/�ٳ���.png");
		break;
	case 1: // ����
		m_pImageInfo = new CImageInfo[5];
		for (int i = 0; i < 5; i++)
		{
			m_pImageInfo[i].SetRect(i * 96, 0, 96, 76);
		}
		CBaseRender::Load("./Images/����.png");
		break;
	case 2: // �䳢
		m_pImageInfo = new CImageInfo[8];
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		CBaseRender::Load("./Images/�䳢.png");
		break;
	case 3: // ����
		m_pImageInfo = new CImageInfo[8];
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		CBaseRender::Load("./Images/����.png");
		break;
	case 4: // ��
		m_pImageInfo = new CImageInfo[8];
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * 96, 0, 96, 76);
		}
		CBaseRender::Load("./Images/��.png");
		break;
	case 5: // ȣ�α��
		m_pImageInfo = new CImageInfo[8];
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		CBaseRender::Load("./Images/ȣ�α��.png");
		break;
	case 6: // ������
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		CBaseRender::Load("./Images/������.png");
		break;
	case 7: // �����
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 96, 0, 96, 76);
		}
		CBaseRender::Load("./Images/�����.png");
		break;
	case 8: // ȣ��
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		CBaseRender::Load("./Images/ȣ��.png");
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

	// �ִϸ��̼� ������ �ӵ� ����
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