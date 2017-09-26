#include "stdafx.h"

CPlayerInfo::CPlayerInfo()
{
	m_eRenderType = eRenderType_Player;

	m_bIsActive = false;

	m_bIsPressLeft = false;
	m_bIsPressRight = false;
	m_bIsPressUp = false;
	m_bIsPressDown = false;
	m_bIsPressZ = false;

	m_nLife = MAX_PLAYER_LIFE;

	m_pImageInfo = new CImageInfo[MAX_PLAYER_FRAME];
}


CPlayerInfo::~CPlayerInfo()
{
}


bool CPlayerInfo::Initialize()
{
	CBaseRender::Initialize();
	CTimeManager::Initialize();

	bulletList = new CBulletManager;
	bulletList->Init();

	m_pGameFrame = new CFrameSkip;
	m_pGameFrame->SetFramePerSec(60);

	//	�⺻ ���� �ִϸ��̼�
	for (int i = 0; i < 8; i++)
	{
		m_pImageInfo[i].SetRect(i * 64, 0, 64, 100);
	}
	CBaseRender::Load("./Images/���ΰ�.png");

	m_vOffset.x = -32.0f;
	m_vOffset.y = -32.0f;

	m_vPos.x = 240;
	m_vPos.y = 600;

	m_pGameFrame = new CFrameSkip();

	CBaseObject::SetUpCollision();

	attackDelay = 30;

	return true;
}

void CPlayerInfo::Terminate()
{
	delete bulletList;
	delete this;
}


bool CPlayerInfo::Pulse()
{

	CTimeManager::Pulse();
	bulletList->Frame(0);
	// ȭ��ǥ ���� �Է¹޴� �κ�
	if (m_bIsPressLeft)		m_vPos.x -= 3;
	if (m_bIsPressRight)	m_vPos.x += 3;
	if (m_bIsPressUp)		m_vPos.y -= 3;
	if (m_bIsPressDown)		m_vPos.y += 3;

	if (attackDelay > 0) attackDelay--;

	// �ִϸ��̼� ������ �ӵ� ����
	float fTimeStep = CTimeManager::GetTimeStep();
	if (m_pGameFrame->Update(fTimeStep))
	{
		static unsigned int frame = 0;
		static float deltaTime = 0;

		if (frame > 7)
		{
			frame = 0;
		}

		m_kImageInfo = m_pImageInfo[frame];
		if (deltaTime >= 0.08f)
		{
			frame++;
			deltaTime = 0;
		}
		deltaTime += fTimeStep;
	}

	if (CheckCollision(Vector2D(10, 10)))
	{
		m_vPos.x = 500;
		m_vPos.y = 500;
	}
	CBaseObject::Pulse();

	//if (m_nLife) { m_bIsActive = false; }

	//if (!m_bIsActive) {
	//	m_vPos.x = -500;
	//	m_vPos.y = -500;
	//}
	return true;
}

void CPlayerInfo::Render()
{
#ifdef _DEBUG
	POINT ptPosText; // ��ǥ�� üũ
	ptPosText.x = m_vPos.x;
	ptPosText.y = m_vPos.y;
	g_pGraphicManager->DrawTextFormat(m_vPos.x, m_vPos.y, 0xFFFF0000, "(%d,%d)", ptPosText.x, ptPosText.y);
#endif
	CBaseRender::RenderSet(m_vPos);
	CBaseObject::Render(mat);
	bulletList->Render();
}

void CPlayerInfo::KeyboardHandler(void)
{
	if (g_pKeyCodeScan(VK_LEFT))	{ m_bIsPressLeft = true; }
	if (!g_pKeyCodeScan(VK_LEFT))	{ m_bIsPressLeft = false; }
	if (g_pKeyCodeScan(VK_RIGHT))	{ m_bIsPressRight = true; }
	if (!g_pKeyCodeScan(VK_RIGHT))	{ m_bIsPressRight = false;}
	if (g_pKeyCodeScan(VK_UP))		{ m_bIsPressUp = true; }
	if (!g_pKeyCodeScan(VK_UP))		{ m_bIsPressUp = false; }
	if (g_pKeyCodeScan(VK_DOWN))	{ m_bIsPressDown = true; }
	if (!g_pKeyCodeScan(VK_DOWN))	{ m_bIsPressDown = false; }
	if (g_pKeyCodeScan('Z') && attackDelay <= 0)		
	{ 
		bulletList->OnObject()->Initialize(0, Vector2D(m_vPos.x, m_vPos.y));
		attackDelay = 30;
	}
	if (!g_pKeyCodeScan('Z'))		{ m_bIsPressZ = false; }
}

void CPlayerInfo::MouseHandler(MOUSESTATE diMouseState)
{
}
