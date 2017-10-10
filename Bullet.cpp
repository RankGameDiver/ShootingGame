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

	m_vPos.x = pos.x;
	m_vPos.y = pos.y;

	switch (m_eEnemyKind)
	{
	case 0: // ������
		m_pImageInfo = new CImageInfo[5];
		m_vWH.x = 70;
		m_vWH.y = 718;
		for (int i = 0; i < 5; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseObject::SetUpCollision(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);
		CBaseRender::Load("./Images/������ ����.png");
		break;
	case 1: // �ٳ���
		m_pImageInfo = new CImageInfo[4];
		m_vWH.x = 56;
		m_vWH.y = 80;
		for (int i = 0; i < 4; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseObject::SetUpCollision(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);
		CBaseRender::Load("./Images/�ٳ��� ����.png");
		break;
	case 2: // ����
		m_pImageInfo = new CImageInfo[6];
		m_vWH.x = 56;
		m_vWH.y = 76;
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseObject::SetUpCollision(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);
		CBaseRender::Load("./Images/���� ����.png");
		break;
	case 3: // �䳢
		m_pImageInfo = new CImageInfo[8];
		m_vWH.x = 56;
		m_vWH.y = 80;
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/�䳢 ����.png");
		break;
	case 4: // ����
		m_pImageInfo = new CImageInfo[8];
		m_vWH.x = 24;
		m_vWH.y = 49;
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/���� ����.png");
		break;
	case 5: // ��
		m_pImageInfo = new CImageInfo[6];
		m_vWH.x = 96;
		m_vWH.y = 76;
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseObject::SetUpCollision(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);
		CBaseRender::Load("./Images/�� ����.png");
		break;
	case 6: // ȣ�α��
		m_pImageInfo = new CImageInfo[8];
		m_vWH.x = 56;
		m_vWH.y = 47;
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/ȣ�α�� ����.png");
		break;
	case 8: // �����
		m_pImageInfo = new CImageInfo[3];
		m_vWH.x = 56;
		m_vWH.y = 60;
		for (int i = 0; i < 3; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseObject::SetUpCollision(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);
		CBaseRender::Load("./Images/����� ����.png");
		break;
	case 9: // ȣ��
		m_pImageInfo = new CImageInfo[6];
		m_vWH.x = 56;
		m_vWH.y = 80;
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseRender::Load("./Images/ȣ�� ����.png");
		break;
	case 10:
		m_pImageInfo = new CImageInfo[1];
		m_vWH.x = 23;
		m_vWH.y = 35;
		m_pImageInfo[0].SetRect(0, 0, m_vWH.x, m_vWH.y);
		CBaseObject::SetUpCollision(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);
		CBaseRender::Load("./Images/����1.png");
	case 11:
		m_pImageInfo = new CImageInfo[1];
		m_vWH.x = 23;
		m_vWH.y = 35;
		m_pImageInfo[0].SetRect(0, 0, m_vWH.x, m_vWH.y);
		CBaseObject::SetUpCollision(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);
		CBaseRender::Load("./Images/����1 ��ȭ.png");
	case 12:
		m_pImageInfo = new CImageInfo[3];
		m_vWH.x = 21;
		m_vWH.y = 44;
		for (int i = 0; i < 3; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseObject::SetUpCollision(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);
		CBaseRender::Load("./Images/����2.png");
	case 13:
		m_pImageInfo = new CImageInfo[3];
		m_vWH.x = 21;
		m_vWH.y = 44;
		for (int i = 0; i < 3; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		CBaseObject::SetUpCollision(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);
		CBaseRender::Load("./Images/����2 ��ȭ.png");
		break;
	default:
		break;
	}
	
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
		if (bulletType >= 1)	{ m_vPos.y += 8; }
		else					{ m_vPos.y -= 8; }

		CBaseObject::Pulse(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);
	}
	return true;
}

void CBullet::Render()
{
	if (GetActive())
	{
		CBaseRender::RenderSet(m_vPos);
		CBaseRender::Render(mat);
		if (m_vPos.y <= -100) { SetActive(false); }
		if (m_vPos.y >= 800) { SetActive(false); }
	}
}