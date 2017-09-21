#include "StdAfx.h"
#include "BaseRender.h"


CBaseRender::CBaseRender(void)
{
	m_iTextureHandle = -1;

	m_vPos = D3DXVECTOR3(0, 0, 0);
	m_vOffset = D3DXVECTOR3(0, 0, 0);

	m_d3dColor = 0xffffffff;
}

CBaseRender::~CBaseRender(void)
{
}

bool CBaseRender::Initialize()
{
	
	return true;
}

void CBaseRender::Terminate()
{
}

bool CBaseRender::Pulse()
{
	return true;
}

void CBaseRender::RenderSet(D3DXVECTOR3 m_vPos)
{
	D3DXMatrixIdentity(&mat);
	D3DXMatrixIdentity(&matS);
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);

	D3DXMatrixScaling(&matS, m_vScale.x, m_vScale.y, m_vScale.z); // 크기

	/*회전
	static float fAngle = 0;
	fAngle += 0.01f;
	D3DXMatrixRotationZ(&matR, fAngle);*/

	D3DXMatrixTranslation(&matT, m_vPos.x, m_vPos.y, 0.0f); // 위치

	mat = matS * matR * matT;
}

void CBaseRender::Render()
{
	LPDIRECT3DTEXTURE9 lpTexture = g_pTextureManager->FindTexture(m_iTextureHandle);

	if (lpTexture)
	{
		D3DXVECTOR3 vPos = m_vPos + m_vOffset;

		g_pGraphicManager->Draw(lpTexture, &vPos, &m_kImageInfo, m_d3dColor);
	}
}

void CBaseRender::Render(D3DXMATRIX mat)
{
	LPDIRECT3DTEXTURE9 lpTexture = g_pTextureManager->FindTexture(m_iTextureHandle);

	if (lpTexture)
	{
		g_pGraphicManager->Draw(lpTexture, &D3DXVECTOR3(0, 0, 0), &m_kImageInfo, mat, m_d3dColor);
	}
}

#ifdef _UNICODE
bool CBaseRender::Load(const TCHAR* szURL)
{
	m_iTextureHandle = g_pTextureManager->GetTexture(szURL);

	if (m_iTextureHandle == -1)
	{
		return false;
	}

	return true;
}
#else
bool CBaseRender::Load(const char* szURL)
{
	m_iTextureHandle = g_pTextureManager->GetTexture(szURL);

	if (m_iTextureHandle == -1)
	{
		return false;
	}

	return true;
}
#endif
