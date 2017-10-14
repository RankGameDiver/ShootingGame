#include "stdafx.h"

CMenu::CMenu(void)
{
	m_fTime = 0.0f;
}

CMenu::~CMenu(void)
{
}

bool CMenu::Initialize()
{
	if (!CBaseRender::Initialize())
	{
		return false;
	}

	m_vPos.x = 0;
	m_vPos.y = 0;

	m_kImageInfo.SetRect(0, 0, 640, 480);
#ifdef _UNICODE
	CBaseRender::Load(L"./Images/Menu.bmp");
#else
	CBaseRender::Load("./Images/Menu.bmp");
#endif
	CBaseRender::SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	return true;
}

void CMenu::Terminate()
{
	CBaseRender::Terminate();
}

bool CMenu::Pulse()
{
	CBaseRender::Pulse();
	return true;
}

void CMenu::Render()
{
	CBaseRender::Render();
}
