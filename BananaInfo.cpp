#include "stdafx.h"

CBananaInfo::CBananaInfo()
{
	m_eRenderType = eRenderType_Enemy;

	m_bIsActive = false;

	m_nLife = MAX_ENEMY_LIFE;
}

CBananaInfo::~CBananaInfo()
{
}

bool CBananaInfo::Initialize()
{
	CBaseObject::Initialize();

	m_pImageInfo = new CImageInfo[1];

	// 기본 동작 애니메이션
	m_pImageInfo[0].SetRect(0, 0, 56, 80);

	m_vOffset.x = -10.0f;
	m_vOffset.y = -10.0f;

	SetPos();
	SetScale();

	m_eActionState = eActionState_Normal;

	CBaseObject::SetUpCollision();
	return true;
}

void CBananaInfo::Terminate()
{

}

bool CBananaInfo::Pulse()
{
	float fOffset = 200 * g_pSystem->GetTimeStep();

	m_eActionState = eActionState::eActionState_Normal;

	m_kImageInfo = m_pImageInfo[0];

	CBaseObject::Pulse();

	return true;
}

void CBananaInfo::Render()
{
	TCHAR buffer[128];
	POINT ptPosText;

	ptPosText.x = m_vPos.x;
	ptPosText.y = m_vPos.y;

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
