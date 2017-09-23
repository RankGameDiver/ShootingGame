#include "stdafx.h"

CBullet::CBullet()
{

}

CBullet::~CBullet()
{

}

bool CBullet::Initialize(Vector2D pos)
{
	CBaseRender::Initialize();

	m_pImageInfo = new CImageInfo[3];
	for (int i = 0; i < 3; i++)
	{
		m_pImageInfo[i].SetRect(i * 24, 0, 24, 49);
	}
	CBaseRender::Load("./Images/총알.png");

	m_vPos.x = pos.x + 20;
	m_vPos.y = pos.y;

	m_pGameFrame = new CFrameSkip();

	CBaseObject::SetUpCollision();
	return true;
}

void CBullet::Terminate()
{
	CBaseRender::Terminate();
}

bool CBullet::Pulse()
{
	CTimeManager::Pulse();
	float fTimeStep = CTimeManager::GetTimeStep();

	// 애니메이션 프레임 속도 조절
	if (m_pGameFrame->Update(fTimeStep))
	{
		static unsigned int frame = 0;
		static float deltaTime = 0;

		if (frame > 2)
		{
			frame = 0;
		}

		m_kImageInfo = m_pImageInfo[frame];
		if (deltaTime >= 0.12f)
		{
			frame++;
			deltaTime = 0;
		}
		deltaTime += fTimeStep;
	}

	m_vPos.y -= 5;

	CBaseObject::Pulse();
	return true;
}

void CBullet::Render()
{
	if (m_bIsActive)
	{
		CBaseRender::RenderSet(m_vPos);
		CBaseRender::Render(mat);
		if (m_vPos.y <= -100) SetActive(false);
	}
}