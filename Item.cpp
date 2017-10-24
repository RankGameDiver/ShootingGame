#include "stdafx.h"

CItem::CItem()
{

}

CItem::~CItem()
{

}

bool CItem::Initialize(Vector2D pos)
{
	CBaseRender::Initialize();

	m_vPos.x = pos.x;
	m_vPos.y = pos.y;

	m_pImageInfo = new CImageInfo[1];
	m_vWH.x = 85;
	m_vWH.y = 85;
	m_pImageInfo[0].SetRect(0, 0, m_vWH.x, m_vWH.y);
	CBaseObject::SetUpCollision(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);

	switch (m_type)
	{
	case 0: // ���ݷ� ����
		CBaseRender::Load("./Images/����UI/���ݷ�����.png");
		break;
	case 1: // ü��ȸ��
		CBaseRender::Load("./Images/����UI/ü��ȸ��.png");
		break;
	case 2: // ���� ����
		CBaseRender::Load("./Images/����UI/��.png");
		break;
	default:
		break;
	}

	return true;
}

void CItem::Terminate()
{
	CBaseRender::Terminate();
}

bool CItem::Pulse(int itemType)
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
			m_kImageInfo = m_pImageInfo[0];
			if (frame > 2) { frame = 0; }
			if (deltaTime >= 0.12f)
			{
				frame++;
				deltaTime = 0;
			}
			deltaTime += fTimeStep;
		}
		m_vPos.y += 4;

		CBaseObject::Pulse(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);
	}
	return true;
}

void CItem::Render()
{
	if (GetActive())
	{
		CBaseRender::RenderSet(m_vPos);
		CBaseRender::Render(mat);
		if (m_vPos.y >= 700) { SetActive(false); }
	}
}