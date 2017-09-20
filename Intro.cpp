#include "stdafx.h"

CIntro::CIntro(void)
{
	m_fTime = 0.0f;
}

CIntro::~CIntro(void)
{
}

bool CIntro::Initialize()
{
	if (!CBaseRender::Initialize())
	{
		return false;
	}

	m_vPos.x = 0;
	m_vPos.y = 0;

	m_kImageInfo.SetRect(0, 0, 640, 480);
#ifdef _UNICODE
	CBaseRender::Load(L"./Images/Intro.bmp");
#else
	CBaseRender::Load("./Images/Intro.bmp");
#endif
	CBaseRender::SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	return true;
}

void CIntro::Terminate()
{
	CBaseRender::Terminate();
}

bool CIntro::Pulse()
{
	CBaseRender::Pulse();

	m_fTime += g_pSystem->GetTimeStep();

	if (m_fTime > 5.0f)
	{
		g_pSystem->ChangeScene(IScene::eSceneType_Stage1);
	}

	return true;
}

void CIntro::Render()
{
	CBaseRender::Render();
}

