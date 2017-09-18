#pragma once
class CImageManager : public CSingleton<CImageManager>
{
private:
	struct IMAGE_INFO
	{
		char szName[_MAX_PATH];
		HDC		hImageDC;
		HBITMAP hBitmap;
		BITMAP  bmpInfo;
	};

public:
	IMAGE_INFO* m_pImage[MAX_IMAGE];
	int m_nIdCount;

public:
	CImageManager(void);
	virtual ~CImageManager(void);

	bool Initialize();
	void Terminate();

	int ImageLoad(const char* szURL);
	HDC FindImage(int nId);
	BITMAP* GetBmpInfo(int nId);
};

#define g_pImageManager	CImageManager::GetSingleton()