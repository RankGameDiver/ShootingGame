#include "stdafx.h"

CEnemy::CEnemy()
{
	m_eRenderType = eRenderType_Enemy;

	m_bIsActive = false;

	move = true; 
	m_type = 0;
}

CEnemy::~CEnemy()
{
}

bool CEnemy::Initialize(Vector2D pos, CPlayerInfo* player)
{
	CBaseRender::Initialize();
	CTimeManager::Initialize();

	bulletList = new CBulletManager;
	bulletList->Init(player);

	item = new CItemManager;
	item->Init(player);

	frame = 0;
	deltaTime = 0;
	m_pImageInfo = new CImageInfo[8];

	switch (m_type)
	{
	case 0: // 리빙돌
		//m_pImageInfo = new CImageInfo[7];
		m_vWH.x = 110;
		m_vWH.y = 136;
		for (int i = 0; i < 7; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		SetLife(50); // 생명 설정
		CBaseRender::Load("./Images/리빙돌.png");
		break;
	case 1: // 바나나
		//m_pImageInfo = new CImageInfo[6];
		m_vWH.x = 56;
		m_vWH.y = 80;
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		SetLife(3);
		CBaseRender::Load("./Images/바나나.png");
		break;
	case 2: // 오너
		//m_pImageInfo = new CImageInfo[5];
		m_vWH.x = 96;
		m_vWH.y = 76;
		for (int i = 0; i < 5; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		SetLife(3);
		CBaseRender::Load("./Images/오너.png");
		break;
	case 3: // 토끼
		//m_pImageInfo = new CImageInfo[8];
		m_vWH.x = 56;
		m_vWH.y = 76;
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		SetLife(3);
		CBaseRender::Load("./Images/토끼.png");
		break;
	case 4: // 인형
		//m_pImageInfo = new CImageInfo[8];
		m_vWH.x = 56;
		m_vWH.y = 76;
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		SetLife(3);
		CBaseRender::Load("./Images/인형.png");
		break;
	case 5: // 콩
		//m_pImageInfo = new CImageInfo[8];
		m_vWH.x = 96;
		m_vWH.y = 76;
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		SetLife(3);
		CBaseRender::Load("./Images/콩.png");
		break;
	case 6: // 호두까기
		//m_pImageInfo = new CImageInfo[8];
		m_vWH.x = 56;
		m_vWH.y = 76;
		for (int i = 0; i < 8; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		SetLife(3);
		CBaseRender::Load("./Images/호두까기.png");
		break;
	case 7: // 강아지
		//m_pImageInfo = new CImageInfo[6];
		m_vWH.x = 56;
		m_vWH.y = 76;
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		SetLife(3);
		CBaseRender::Load("./Images/강아지.png");
		break;
	case 8: // 보라색
		//m_pImageInfo = new CImageInfo[6];
		m_vWH.x = 96;
		m_vWH.y = 76;
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		SetLife(3);
		CBaseRender::Load("./Images/보라색.png");
		break;
	case 9: // 호박
		//m_pImageInfo = new CImageInfo[6];
		m_vWH.x = 56;
		m_vWH.y = 76;
		for (int i = 0; i < 6; i++)
		{
			m_pImageInfo[i].SetRect(i * m_vWH.x, 0, m_vWH.x, m_vWH.y);
		}
		SetLife(3);
		CBaseRender::Load("./Images/호박.png");
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

	if (m_type == 0)						maxFrame = 7;
	else if (m_type == 1 || m_type >= 7)	maxFrame = 6;
	else if (m_type == 2)					maxFrame = 5;
	else if (m_type >= 3 && m_type <= 6)	maxFrame = 6;

	// 애니메이션 프레임 속도 조절
	float fTimeStep = CTimeManager::GetTimeStep();
	if (m_pGameFrame->Update(fTimeStep))
	{
		if (frame >= maxFrame)
		{
			frame = 0;
			bulletList->OnObject(m_type)->Initialize(Vector2D(m_vPos.x, m_vPos.y)); // 총알 종류 변경
		}
		m_kImageInfo = m_pImageInfo[frame]; // 몬스터 이미지 출력
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
		if (m_vPos.x >= 400)	move = false;
	}
	else
	{
		m_vPos.x -= 1;
		if (m_vPos.x <= 10)		move = true;
	}

	CBaseObject::Pulse(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);

	if (m_nLife <= 0)
	{
		m_bIsActive = false;
		item = new CItemManager;
		delete[] m_pImageInfo;
	}

	return true;
}

void CEnemy::Render()
{
	POINT ptPosText;

	ptPosText.x = m_vPos.x;
	ptPosText.y = m_vPos.y;

	g_pGraphicManager->DrawTextFormat(m_vPos.x, m_vPos.y, 0xFFFF0000, "(%d,%d)", ptPosText.x, ptPosText.y);

	bulletList->Render();
	CBaseRender::RenderSet(m_vPos);
	CBaseObject::Render(mat);
}