#include "stdafx.h"

CBackGround::CBackGround()
{
	m_eRenderType = eRenderType_BackGround;

	m_pImageInfo = new CImageInfo[1];
}


CBackGround::~CBackGround()
{
}


bool CBackGround::Initialize()
{
	CBaseRender::Initialize();

	m_pImageInfo[0].SetRect(0, 0, 564, 3000);

	m_vPos.x = 0;
	m_vPos.y = 0;

	m_vScale.x = 1.0f;
	m_vScale.y = 1.0f;
	m_vScale.z = 1.0f;

	/*SetPos(m_vPos);
	SetScale(m_vScale);*/

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