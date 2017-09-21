#include "stdafx.h"

CBullet::CBullet()
{
	m_eRenderType = eRenderType_Bullet;

	m_bIsActive = false;
	//m_pPlayer = 
}

CBullet::~CBullet()
{

}

bool CBullet::Initialize()
{
	CBaseRender::Initialize();

	m_vOffset.x = -20.0f;
	m_vOffset.y = -20.0f;

//	m_vPos.x = 
//	m_vPos.y = 

	m_vScale.x = 1.0f;
	m_vScale.y = 1.0f;
	m_vScale.z = 1.0f;

	m_eActionState = eActionState_Normal;

	CBaseObject::SetUpCollision();
	return true;
}

void CBullet::Terminate()
{

}

bool CBullet::Pulse()
{
	float fOffset = 200 * g_pSystem->GetTimeStep();

	//if (CheckCollision(GetCollision()))
	//{
	//	
	//}

	CBaseObject::Pulse();
	return true;
}

void CBullet::Render()
{
	CBaseRender::RenderSet(m_vPos, m_vScale);
	CBaseRender::Render(mat);
}