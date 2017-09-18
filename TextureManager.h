#pragma once

class CTextureManager : public CSingleton<CTextureManager>
{
public:
	struct S_TextureInfo
	{
#ifdef _UNICODE
		TCHAR szName[_MAX_PATH];
#else
		char szName[_MAX_PATH];
#endif
		LPDIRECT3DTEXTURE9 lpTexture;
	};

public:
	int m_iCurHandle;

	S_TextureInfo* m_pTextureList[MAX_TEXTURE];

public:
	CTextureManager(void);
	virtual ~CTextureManager(void);

public:
	bool Initialize();
	void Terminate();
#ifdef _UNICODE
	int GetTexture(const TCHAR* szURL);
#else
	int GetTexture(const char* szURL);
#endif
	LPDIRECT3DTEXTURE9 FindTexture(int iHandle);
};

#define g_pTextureManager	CTextureManager::GetSingleton()
