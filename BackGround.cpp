#include "stdafx.h"

CBackGround::CBackGround()
{
	m_eRenderType = eRenderType_BackGround;

	m_pImageInfo = new CImageInfo[1];
}


CBackGround::~CBackGround()
{
}


bool CBackGround::Initialize(int a)
{
	CBaseRender::Initialize();

	m_pImageInfo[0].SetRect(0, 0, 1024, 3000);   //564

	m_vPos.x = a;
	m_vPos.y = 0;

	m_vScale.x = 1.0f;
	m_vScale.y = 1.0f;
	m_vScale.z = 1.0f;

	return true;
}

bool CBackGround::Initialize(int a,int b)
{
	CBaseRender::Initialize();

	m_pImageInfo[0].SetRect(0, 0, 1024, 3000);   //564

	m_vPos.x = a;
	m_vPos.y = b;

	m_vScale.x = 1.0f;
	m_vScale.y = 1.0f;
	m_vScale.z = 1.0f;

	return true;
}

void CBackGround::Terminate()
{

}


bool CBackGround::Pulse()
{
	CBaseObject::Pulse(m_vPos.x, m_vPos.y, m_vWH.x, m_vWH.y);

	m_kImageInfo = m_pImageInfo[0];

	return true;
}

void CBackGround::Render()
{
	CBaseRender::RenderSet(m_vPos);
	CBaseObject::Render(mat);
}