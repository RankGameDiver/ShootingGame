#include "stdafx.h"

CGraphicManager::CGraphicManager()
{
	m_bIsFullScreen = false;
}


CGraphicManager::~CGraphicManager()
{
}

bool CGraphicManager::InitDirect3D()
{
	m_lpD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (!m_lpD3D)
	{
#ifdef _UNICODE
		MessageBox(0, L"DirectX 9 RunTime을 설치하세요.", L"Error", 0);
#else
		MessageBox(0, "DirectX 9 RunTime을 설치하세요.", "Error", 0);
#endif
		PostQuitMessage(0);
		return false;
	}
	return true;
}

void CGraphicManager::TermDirect3D()
{
	if (m_lpD3D)
	{
		m_lpD3D->Release();
		m_lpD3D = NULL;
	}
}

bool CGraphicManager::InitDirect3DDevice()
{
	D3DPRESENT_PARAMETERS d3dpp;

	D3DDISPLAYMODE d3dDisplayMode;

	m_lpD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3dDisplayMode);

	D3DCAPS9 d3dCaps;

	m_lpD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &d3dCaps);

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.hDeviceWindow = g_pSystem->GetHandle();
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.BackBufferFormat = d3dDisplayMode.Format;
	if (!d3dpp.Windowed)
	{
		d3dpp.BackBufferCount = 1;
		d3dpp.BackBufferWidth = SCREEN_WIDTH;
		d3dpp.BackBufferHeight = SCREEN_HEIGHT;
		d3dpp.FullScreen_RefreshRateInHz = d3dDisplayMode.RefreshRate;
	}
	d3dpp.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;


	HRESULT hr;

	hr = m_lpD3D->CreateDevice(
		D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_pSystem->GetHandle(),
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp, &m_lpD3DD);

	if (FAILED(hr)) { return false; }

	return true;
}

void CGraphicManager::TermDirect3DDevice()
{
	if (m_lpD3DD)
	{
		m_lpD3DD->Release();
		m_lpD3DD = NULL;
	}
}

bool CGraphicManager::Initialize()
{
	HRESULT hr;

	InitDirect3D();
	InitDirect3DDevice();

	hr = D3DXCreateSprite(m_lpD3DD, &m_lpSprite);

	if (FAILED(hr)){	return false; }
#ifdef _UNICODE
	hr = D3DXCreateFont(m_lpD3DD, 12, 0, 0, 0, false,
		HANGUL_CHARSET, OUT_TT_ONLY_PRECIS, 
		DEFAULT_QUALITY, DEFAULT_PITCH,
		L"굴림체", &m_lpFont);
#else
	hr = D3DXCreateFont(m_lpD3DD, 12, 0, 0, 0, false,
		HANGUL_CHARSET, OUT_TT_ONLY_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH,
		"굴림체", &m_lpFont);
#endif
	if (FAILED(hr)){	return false; }

	m_hDC = CreateCompatibleDC(NULL);

	return true;
}

void CGraphicManager::Terminate()
{
	ReleaseDC(g_pSystem->GetHandle(), m_hDC);
	TermDirect3D();
	TermDirect3DDevice();
}

void CGraphicManager::Pulse()
{
}

void CGraphicManager::PreRender()
{
	m_lpD3DD->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	m_lpD3DD->BeginScene();
}

void CGraphicManager::PostRender()
{
	m_lpD3DD->EndScene();

	HRESULT hr = m_lpD3DD->Present(NULL, NULL, NULL, NULL);
}

void CGraphicManager::Draw(LPDIRECT3DTEXTURE9 lpTexture, D3DXVECTOR3* pvPos, RECT* prtRect, D3DXMATRIX mtMatrix, D3DCOLOR d3dColor)
{
	m_lpSprite->SetTransform(&mtMatrix);
	m_lpSprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_lpSprite->Draw(lpTexture, prtRect, NULL, pvPos, d3dColor);
	m_lpSprite->End();
}

void CGraphicManager::Draw(LPDIRECT3DTEXTURE9 lpTexture, D3DXVECTOR3* pvPos, RECT* prtRect, D3DCOLOR d3dColor)
{
	D3DXMATRIX mtMatrix;
	D3DXMatrixIdentity(&mtMatrix);
	m_lpSprite->SetTransform(&mtMatrix);
	m_lpSprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_lpSprite->Draw(lpTexture, prtRect, NULL, pvPos, d3dColor);
	m_lpSprite->End();
}

#ifdef _UNICODE
void CGraphicManager::DrawText(int ix, int iy, const TCHAR* szString, D3DCOLOR d3dColor, int iLength, DWORD dwFormat)
{
	int iStringLength;

	if (iLength == -1)	iStringLength = (int)wcslen(szString);
	else					iStringLength = iLength;

	SIZE siSize;
	GetTextExtentPoint32(m_hDC, szString, iStringLength, &siSize);

	RECT rtRect;
	rtRect.left = ix;
	rtRect.top = iy;
	rtRect.right = ix + siSize.cx + 5;
	rtRect.bottom = iy + siSize.cy;

	m_lpFont->DrawText(NULL, szString, iStringLength, &rtRect, dwFormat, d3dColor);
}
void CGraphicManager::DrawTextFormat(int ix, int iy, D3DCOLOR d3dColor, const TCHAR* szFormat, ...)
{
	TCHAR strString[512];
	va_list args;
	va_start(args, szFormat);
	_vsntprintf(strString, 512, szFormat, args);
	va_end(args);

	DrawText(ix, iy, strString, d3dColor);
}
#else
void CGraphicManager::DrawText(int ix, int iy, const char* szString, D3DCOLOR d3dColor, int iLength, DWORD dwFormat)
{
	int iStringLength;

	if (iLength == -1)	iStringLength = (int)strlen(szString);
	else					iStringLength = iLength;

	SIZE siSize;
	GetTextExtentPoint32(m_hDC, szString, iStringLength, &siSize);

	RECT rtRect;
	rtRect.left = ix;
	rtRect.top = iy;
	rtRect.right = ix + siSize.cx + 5;
	rtRect.bottom = iy + siSize.cy;

	m_lpFont->DrawText(NULL, szString, iStringLength, &rtRect, dwFormat, d3dColor);
}

void CGraphicManager::DrawTextFormat(int ix, int iy, D3DCOLOR d3dColor, const char* szFormat, ...)
{
	char strString[512];
	va_list args;
	va_start(args, szFormat);
	_vsntprintf(strString, 512, szFormat, args);
	va_end(args);

	DrawText(ix, iy, strString, d3dColor);
}
#endif
