#include "stdafx.h"

CPlayerInfo::CPlayerInfo()
{
	m_eRenderType = eRenderType_Player;

	m_bIsActive = false;

	m_bIsPressLeft = false;
	m_bIsPressRight = false;
	m_bIsPressUp = false;
	m_bIsPressDown = false;

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

	m_pGameFrame = new CFrameSkip;
	m_pGameFrame->SetFramePerSec(60);

	//	기본 동작 애니메이션
	for (int i = 0; i < 8; i++)
	{
		m_pImageInfo[i].SetRect(i * 64, 0, 64, 100);
	}

	m_vOffset.x = -32.0f;
	m_vOffset.y = -32.0f;

	m_vPos.x = 320;
	m_vPos.y = 240;

	m_vScale.x = 1.0f;
	m_vScale.y = 1.0f;
	m_vScale.z = 1.0f;

	SetPos(m_vPos);
	SetScale(m_vScale);

	m_eActionState = eActionState_Normal;

	m_pGameFrame = new CFrameSkip();

	CBaseObject::SetUpCollision();

	return true;
}

void CPlayerInfo::Terminate()
{

}


bool CPlayerInfo::Pulse()
{
	CTimeManager::Pulse();

	float fOffset = MAX_PLAYER_SPEED * g_pSystem->GetTimeStep();

	m_eActionState = eActionState::eActionState_Normal;

	// 화살표 방향 입력받는 부분
	if (m_bIsPressLeft)
	{
		m_eActionState = eActionState::eActionState_Left;
		m_vPos.x -= fOffset;
	}
	if (m_bIsPressRight)
	{
		m_eActionState = eActionState::eActionState_Right;
		m_vPos.x += fOffset;
	}
	if (m_bIsPressUp)
	{
		m_eActionState = eActionState::eActionState_Up;
		m_vPos.y -= fOffset;
	}
	if (m_bIsPressDown)
	{
		m_eActionState = eActionState::eActionState_Down;
		m_vPos.y += fOffset;
	}

	float fTimeStep = CTimeManager::GetTimeStep();

	//// 애니메이션 프레임 속도 조절
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

	CBaseObject::Pulse();

	return true;
}

void CPlayerInfo::Render()
{
	TCHAR buffer[128];
	POINT ptPosText; // 좌표값 체크
	
	ptPosText.x = m_vPos.x;
	ptPosText.y = m_vPos.y + (m_kImageInfo.m_siSize.cy / 2);

#ifdef _DEBUG
#ifdef _UNICODE
	g_pGraphicManager->DrawTextFormat(m_vPos.x, m_vPos.y, 0xFFFFFF00, L"(%d,%d)", ptPosText.x, ptPosText.y);
#else
	g_pGraphicManager->DrawTextFormat(m_vPos.x, m_vPos.y, 0xFFFF0000, "(%d,%d)", ptPosText.x, ptPosText.y);
#endif
#endif
	
	CBaseRender::RenderSet(m_vPos, m_vScale);

	CBaseObject::Render(mat);
}

void CPlayerInfo::KeyboardHandler(void)
{
	if (g_pKeyCodeScan(VK_LEFT))	{ m_bIsPressLeft = true;	}
	if (!g_pKeyCodeScan(VK_LEFT))	{ m_bIsPressLeft = false; }
	if (g_pKeyCodeScan(VK_RIGHT))	{ m_bIsPressRight = true; }
	if (!g_pKeyCodeScan(VK_RIGHT))	{ m_bIsPressRight = false;}
	if (g_pKeyCodeScan(VK_UP)) { m_bIsPressUp = true; }
	if (!g_pKeyCodeScan(VK_UP)) { m_bIsPressUp = false; }
	if (g_pKeyCodeScan(VK_DOWN)) { m_bIsPressDown = true; }
	if (!g_pKeyCodeScan(VK_DOWN)) { m_bIsPressDown = false; }
}

void CPlayerInfo::MouseHandler(MOUSESTATE diMouseState)
{
}
