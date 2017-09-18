#include "stdafx.h"
#include "ButtonObject.h"


CButtonObject::CButtonObject()
{
}


CButtonObject::~CButtonObject()
{
}

bool CButtonObject::Initialize()
{
	CBaseObject::Initialize();

	m_pImageInfo = new CImageInfo[MAX_PLAYER_FRAME];

	//	기본 동작
	m_pImageInfo[0].SetRect(0, 0, 64, 64);
	m_pImageInfo[1].SetRect(64, 0, 64, 64);
	m_pImageInfo[2].SetRect(128, 0, 64, 64);


	m_vOffset.x = -32.0f;
	m_vOffset.y = -32.0f;

	m_vPos.x = 320;
	m_vPos.y = 240;

	m_eActionState = eActionState_Normal;

	CBaseObject::SetUpCollision();

	return true;
}

void CButtonObject::Terminate()
{
	delete[] m_pImageInfo;

	CBaseObject::Terminate();
}


bool CButtonObject::Pulse()
{
	float fOffset = MAX_PLAYER_SPEED * g_pSystem->GetTimeStep();

	m_eActionState = eActionState::eActionState_Normal;


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

void CButtonObject::Render()
{
#ifdef _DEBUG
	POINT ptPosText;
	TCHAR buffer[128];

	ptPosText.x = m_vPos.x;
	ptPosText.y = m_vPos.y + (m_kImageInfo.m_siSize.cy / 2);

	g_pGdi->TransparentText();
#ifdef _UNICODE
	wsprintf(buffer, L"(%d,%d)", ptPosText.x, ptPosText.y);
	g_pGdi->TextAtPos(ptPosText.x, ptPosText.y, buffer);
#else
	wsprintf(buffer, "(%.2f,%.2f)", m_vPos.x, m_vPos.y);
	g_pGdi->TextAtPos(ptPosText.x, ptPosText.y, buffer);
#endif
	g_pGdi->OpaqueText();
#endif
	CBaseObject::Render();
}
