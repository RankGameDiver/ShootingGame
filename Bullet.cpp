#include "stdafx.h"

CBullet::CBullet()
{

}

CBullet::~CBullet()
{

}

bool CBullet::Initialize(int m_eEnemyKind, Vector2D pos)
{
	CBaseRender::Initialize();

	switch (m_eEnemyKind)
	{
	case 0:
		m_pImageInfo = new CImageInfo[3];
		for (int i = 0; i < 3; i++)
		{
			m_pImageInfo[i].SetRect(i * 24, 0, 24, 49);
		}
		CBaseRender::Load("./Images/�Ѿ�.png");
		break;
	case 1: // �ٳ���
		m_pImageInfo = new CImageInfo[4];
		for (int i = 0; i < 4; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 80);
		}
		CBaseRender::Load("./Images/�ٳ��� ����.png");
		break;
	case 2: // ����
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		CBaseRender::Load("./Images/���� ����.png");
		break;
	case 3: // �䳢
		//m_pImageInfo = new CImageInfo[8];
		//for (int i = 0; i < 8; i++)
		//{
		//	m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		//}
		//CBaseRender::Load("./Images/�䳢 ����.png");
		break;
	case 4: // ����
		//m_pImageInfo = new CImageInfo[8];
		//for (int i = 0; i < 8; i++)
		//{
		//	m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		//}
		//CBaseRender::Load("./Images/���� ����.png");
		break;
	case 5: // ��
		m_pImageInfo = new CImageInfo[6];
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * 96, 0, 96, 76);
		}
		CBaseRender::Load("./Images/�� ����.png");
		break;
	case 6: // ȣ�α��
		//m_pImageInfo = new CImageInfo[8];
		//for (int i = 0; i < 8; i++)
		//{
		//	m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		//}
		//CBaseRender::Load("./Images/ȣ�α�� ����.png");
		break;
	case 7: // ������
		//m_pImageInfo = new CImageInfo[6];
		//for (int i = 0; i < 6; i++)
		//{
		//	m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		//}
		//CBaseRender::Load("./Images/������ ����.png");
		break;
	case 8: // �����
		m_pImageInfo = new CImageInfo[3];
		for (int i = 0; i < 3; i++)
		{
			m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		}
		CBaseRender::Load("./Images/����� ����.png");
		break;
	case 9: // ȣ��
		//m_pImageInfo = new CImageInfo[6];
		//for (int i = 0; i < 6; i++)
		//{
		//	m_pImageInfo[i].SetRect(i * 56, 0, 56, 76);
		//}
		//CBaseRender::Load("./Images/ȣ�� ����.png");
		break;
	default:
		break;
	}

	m_vPos.x = pos.x + 20;
	m_vPos.y = pos.y;

	m_pGameFrame = new CFrameSkip();

	CBaseObject::SetUpCollision();
	return true;
}

void CBullet::Terminate()
{
	CBaseRender::Terminate();
}

bool CBullet::Pulse(int bulletType)
{
	if (GetActive())
	{
		CTimeManager::Pulse();
		float fTimeStep = CTimeManager::GetTimeStep();

		// �ִϸ��̼� ������ �ӵ� ����
		if (m_pGameFrame->Update(fTimeStep))
		{
			static unsigned int frame = 0;
			static float deltaTime = 0;

			if (frame > 2)
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
		if (bulletType >= 1)	{ m_vPos.y += 5; }
		else					{ m_vPos.y -= 5; }

		CBaseObject::Pulse();
	}
	return true;
}

void CBullet::Render()
{
	if (GetActive())
	{
		CBaseRender::RenderSet(m_vPos);
		CBaseRender::Render(mat);
		if (m_vPos.y <= -100) SetActive(false);
	}
}