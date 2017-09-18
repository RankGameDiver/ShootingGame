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
	CBaseObject::Initialize();

	//	기본 동작 애니메이션
	m_pImageInfo[0].SetRect(0, 0, 64, 100);
	m_pImageInfo[1].SetRect(64, 0, 64, 100);
	m_pImageInfo[2].SetRect(128, 0, 64, 100);
	m_pImageInfo[3].SetRect(192, 0, 64, 100);
	m_pImageInfo[4].SetRect(256, 0, 64, 100);
	m_pImageInfo[5].SetRect(320, 0, 64, 100);
	m_pImageInfo[6].SetRect(384, 0, 64, 100);
	m_pImageInfo[7].SetRect(448, 0, 64, 100);
	

	m_vOffset.x = -32.0f;
	m_vOffset.y = -32.0f;

	m_vPos.x = 320;
	m_vPos.y = 240;

	m_vScale.x = 1.5f;
	m_vScale.y = 1.5f;
	m_vScale.z = 1.0f;

	SetPos(m_vPos);
	SetScale(m_vScale);

	m_eActionState = eActionState_Normal;

	CBaseObject::SetUpCollision();

	return true;
}

void CPlayerInfo::Terminate()
{

}


bool CPlayerInfo::Pulse()
{
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

	// 입력받는 값에 따라서 이미지 출력(앞이나 뒤로 이동할때는 현재 없음)
	switch (m_eActionState)
	{
	case eActionState::eActionState_Normal:
		m_kImageInfo = m_pImageInfo[0];
		break;
	case eActionState::eActionState_Left:
		m_kImageInfo = m_pImageInfo[1];
		break;
	case eActionState::eActionState_Right:
		m_kImageInfo = m_pImageInfo[2];
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
