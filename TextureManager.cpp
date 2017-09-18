#include "stdafx.h"
#include "TextureManager.h"


CTextureManager::CTextureManager(void)
{
	m_iCurHandle = 0;

	for (int iCount = 0; iCount < MAX_TEXTURE; iCount++)
	{
		m_pTextureList[iCount] = NULL;
	}
}

CTextureManager::~CTextureManager(void)
{
}

bool CTextureManager::Initialize()
{
	return true;
}

void CTextureManager::Terminate()
{
}

#ifdef _UNICODE
int CTextureManager::GetTexture(const TCHAR* szURL)
{
	for (int iCount = 0; iCount < MAX_TEXTURE; iCount++)
	{
		if (m_pTextureList[iCount])
		{
			if (_tcsicmp(szURL, m_pTextureList[iCount]->szName) == 0)
			{
				return iCount;
			}
		}
	}

	m_pTextureList[m_iCurHandle] = new S_TextureInfo;

	_tcscpy(m_pTextureList[m_iCurHandle]->szName, szURL);

	HRESULT hr;

	hr = D3DXCreateTextureFromFileEx(
		g_pGraphicManager->GetD3DD(),
		szURL,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DPOOL_DEFAULT,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		0xFF000000,
		NULL,
		NULL,
		&m_pTextureList[m_iCurHandle]->lpTexture
		);

	if (FAILED(hr))
	{
		return -1;
	}

	int iTempHandle = m_iCurHandle;

	m_iCurHandle++;

	return iTempHandle;
}

#else
int CTextureManager::GetTexture(const char* szURL)
{
	for (int iCount = 0; iCount < MAX_TEXTURE; iCount++)
	{
		if (m_pTextureList[iCount])
		{
			if (stricmp(szURL, m_pTextureList[iCount]->szName) == 0)
			{
				return iCount;
			}
		}
	}

	m_pTextureList[m_iCurHandle] = new S_TextureInfo;

	strcpy(m_pTextureList[m_iCurHandle]->szName, szURL);

	HRESULT hr;

	hr = D3DXCreateTextureFromFileEx(
		g_pGraphicManager->GetD3DD(),
		szURL,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DPOOL_DEFAULT,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		0xFF000000,
		NULL,
		NULL,
		&m_pTextureList[m_iCurHandle]->lpTexture
		);

	if (FAILED(hr))
	{
		return -1;
	}

	int iTempHandle = m_iCurHandle;

	m_iCurHandle++;

	return iTempHandle;
}
#endif

LPDIRECT3DTEXTURE9 CTextureManager::FindTexture(int iHandle)
{
	if (iHandle < 0 || iHandle > MAX_TEXTURE)
	{
		return NULL;
	}

	if (m_pTextureList[iHandle])
	{
		return m_pTextureList[iHandle]->lpTexture;
	}

	return NULL;
}
