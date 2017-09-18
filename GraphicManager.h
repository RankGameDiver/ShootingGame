#pragma once

#define D3DFVF_SPRITEVERTEX (D3DFVF_XYZ|D3DFVF_TEX1)

struct SPRITE_VERTEX
{
	float x, y, z;
	float u, v;
};

class CGraphicManager : 
	public CSingleton<CGraphicManager>
{
public:
	LPDIRECT3D9				m_lpD3D;	//d3d°´Ã¼			
	LPDIRECT3DDEVICE9		m_lpD3DD;	//d3d device °´Ã¼	
	LPD3DXSPRITE			m_lpSprite;	//Sprite Interface	
	LPD3DXFONT				m_lpFont;	//Font Interface		
	D3DPRESENT_PARAMETERS	m_d3dpp;     //d3d device ¼³Á¤
	HDC m_hDC;

	bool m_bIsFullScreen;

public:
	CGraphicManager(void);
	virtual ~CGraphicManager(void);
private:
	bool InitDirect3D();		
	void TermDirect3D();		
	bool InitDirect3DDevice();	
	void TermDirect3DDevice();
public:
	__inline LPDIRECT3DDEVICE9 GetD3DD() const;
	bool Initialize();
	void Terminate();
	void Pulse();
	void PreRender();
	void PostRender();

	void Draw(LPDIRECT3DTEXTURE9 lpTexture, D3DXVECTOR3* pvPos, RECT* prtRect, D3DXMATRIX mtMatrix, D3DCOLOR d3dColor = 0xFFFFFFFF);
	void Draw(LPDIRECT3DTEXTURE9 lpTexture, D3DXVECTOR3* pvPos, RECT* prtRect, D3DCOLOR d3dColor = 0xFFFFFFFF);
#ifdef _UNICODE
	void DrawText(int ix, int iy, const TCHAR* szString, D3DCOLOR d3dColor = 0xFFFFFFFF, int iLength = -1, DWORD dwFormat = DT_SINGLELINE | DT_LEFT | DT_VCENTER);
	void DrawTextFormat(int ix, int iy, D3DCOLOR d3dColor, const TCHAR* szFormat, ...);
#else
	void DrawText(int ix, int iy, const char* szString, D3DCOLOR d3dColor = 0xFFFFFFFF, int iLength = -1, DWORD dwFormat = DT_SINGLELINE | DT_LEFT | DT_VCENTER);
	void DrawTextFormat(int ix, int iy, D3DCOLOR d3dColor, const char* szFormat, ...);
#endif
};

__inline LPDIRECT3DDEVICE9 CGraphicManager::GetD3DD() const
{
	return m_lpD3DD;
}

#define g_pGraphicManager CGraphicManager::GetSingleton()