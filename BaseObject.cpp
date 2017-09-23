#include "stdafx.h"

CBaseObject::CBaseObject()
{
	m_siCollision.cx = 0;
	m_siCollision.cy = 0;
	m_ptCollisionOffset.x = 0;
	m_ptCollisionOffset.y = 0;
	m_kCollision.SetRect(0, 0, 0, 0);
	m_pImageInfo = NULL;
}

CBaseObject::~CBaseObject()
{
}

void CBaseObject::SetUpCollision() // 콜라이더 생성
{
	m_siCollision.cx = (int)m_pImageInfo[0].GetSize().cx;
	m_siCollision.cy = (int)m_pImageInfo[0].GetSize().cy;

	m_ptCollisionOffset.x = (m_siCollision.cx / 2) - (m_pImageInfo[0].GetSize().cx / 2);
	m_ptCollisionOffset.y = (m_siCollision.cy / 2) - (m_pImageInfo[0].GetSize().cy / 2);

	m_kCollision.SetRect(
		m_vPos.x + m_ptCollisionOffset.x - m_siCollision.cx / 2,
		m_vPos.y + m_ptCollisionOffset.y - m_siCollision.cy / 2,
		m_siCollision.cx,
		m_siCollision.cy);
}

bool CBaseObject::CheckCollision(Vector2D vPos) // 콜라이더 충돌 체크(좌표로 충돌 처리)
{
	POINT ptPos;
	ptPos.x = (int)vPos.x;
	ptPos.y = (int)vPos.y;

	if (PtInRect(&m_kCollision, ptPos))
	{
		return true;
	}
	return false;
}

bool CBaseObject::CheckCollision(CImageInfo* collision1, CImageInfo* collision2) // 콜라이더 충돌 체크
{
	if (EqualRect(collision1, collision2))
	{
		return true;
	}
	return false;
}

bool CBaseObject::Pulse()
{
	CBaseRender::Pulse();

	m_kCollision.SetRect(
		m_vPos.x + m_ptCollisionOffset.x - m_siCollision.cx / 2,
		m_vPos.y + m_ptCollisionOffset.y - m_siCollision.cy / 2,
		m_siCollision.cx,
		m_siCollision.cy);

	return true;
}