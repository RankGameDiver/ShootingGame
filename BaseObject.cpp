#include "stdafx.h"

CBaseObject::CBaseObject()
{
	m_siCollision.cx = 0;
	m_siCollision.cy = 0;
	m_ptCollisionOffset.x = 0;
	m_ptCollisionOffset.y = 0;
	m_kCollision.SetRect(0, 0, 0, 0);
	m_pImageInfo = NULL;
	m_pGameFrame = new CFrameSkip();
}

CBaseObject::~CBaseObject()
{
}

void CBaseObject::SetUpCollision(int x, int y, int w, int h) // 콜라이더 생성
{
	m_kCollision.SetRect(x, y, w, h);
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
//	collision1->left -= 9;

	int left2 = collision2->left;
	int right2 = collision2->right;
	int top2 = collision2->top;
	int bottom2 = collision2->bottom;

	POINT lb;
	lb.x = left2;
	lb.y = bottom2;

	POINT lb2;
	lb2.x = left2 + 20;
	lb2.y = bottom2;

	POINT rb;
	rb.x = right2;
	rb.y = bottom2;

	POINT rb2;
	rb2.x = right2 - 20;
	rb2.y = bottom2;

	POINT lt;
	lt.x = left2;
	lt.y = top2;

	POINT lt2;
	lt2.x = left2 + 20;
	lt2.y = top2;

	POINT rt;
	rt.x = right2;
	rt.y = top2;

	POINT rt2;
	rt2.x = right2 - 20;
	rt2.y = top2;

	if (PtInRect(collision1,lb) || PtInRect(collision1, lb2) || PtInRect(collision1, rb) || PtInRect(collision1, rb2))
	{
		return true;
	}

	if (PtInRect(collision1, lt) || PtInRect(collision1, lt2) || PtInRect(collision1, rt) || PtInRect(collision1, rt2))
	{
		return true;
	}

	return false;
}

bool CBaseObject::Pulse(int x, int y, int w, int h)
{
	CBaseRender::Pulse();

	m_kCollision.SetRect(x, y, w, h);

	return true;
}