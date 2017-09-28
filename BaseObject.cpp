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

void CBaseObject::SetUpCollision(int x, int y, int w, int h) // �ݶ��̴� ����
{
	m_kCollision.SetRect(x, y, w, h);
}

bool CBaseObject::CheckCollision(Vector2D vPos) // �ݶ��̴� �浹 üũ(��ǥ�� �浹 ó��)
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

bool CBaseObject::CheckCollision(CImageInfo* collision1, CImageInfo* collision2) // �ݶ��̴� �浹 üũ
{
	collision1->left -= 9;
	int left2 = collision2->left;
	int right2 = collision2->right;
	int top2 = collision2->top;
	int bottom2 = collision2->bottom;

	POINT lt;
	lt.x = left2;
	lt.y = top2;

	POINT lb;
	lb.x = left2;
	lb.y = bottom2;

	POINT rt;
	rt.x = right2;
	rt.y = top2;

	POINT rb;
	rb.x = right2;
	rb.y = bottom2;


	if (PtInRect(collision1, lt) || PtInRect(collision1, lb) || PtInRect(collision1, rt) || PtInRect(collision1, rb))
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