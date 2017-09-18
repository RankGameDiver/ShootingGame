#include "StdAfx.h"
#include "ImageManager.h"


CImageManager::CImageManager(void)
{
	m_nIdCount = 0;

	for (int nCnt = 0; nCnt < MAX_IMAGE; nCnt++)
	{
		m_pImage[nCnt] = NULL;
	}
}


CImageManager::~CImageManager(void)
{
}

bool CImageManager::Initialize()
{
	return true;
}

void CImageManager::Terminate()
{
}

int CImageManager::ImageLoad(const char* szURL)
{
	for (int nCnt = 0; nCnt < MAX_IMAGE; nCnt++)
	{
		if (m_pImage[nCnt])
		{
			if (stricmp(szURL, m_pImage[nCnt]->szName) == 0)
			{
				return nCnt;
			}
		}
	}

	m_pImage[m_nIdCount] = new IMAGE_INFO;
	strcpy(m_pImage[m_nIdCount]->szName, szURL);

	HINSTANCE hInst = GetModuleHandle(NULL);

	m_pImage[m_nIdCount]->hImageDC = CreateCompatibleDC(CGdi::Instance()->GetDrawDC());
#ifdef _UNICODE
	TCHAR szUrlUnicode[MAX_LOADSTRING] = L"";
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szURL, strlen(szURL), szUrlUnicode, 256);
	m_pImage[m_nIdCount]->hBitmap = (HBITMAP)LoadImage(hInst, szUrlUnicode, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
#else
	m_pImage[m_nIdCount]->hBitmap = (HBITMAP)LoadImage(hInst, szURL, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
#endif

	SelectObject(m_pImage[m_nIdCount]->hImageDC, m_pImage[m_nIdCount]->hBitmap);
	GetObject(m_pImage[m_nIdCount]->hBitmap, sizeof(BITMAP), &m_pImage[m_nIdCount]->bmpInfo);

	int nTempID = m_nIdCount;

	m_nIdCount++;

	return nTempID;
}

HDC CImageManager::FindImage(int nId)
{
	if (nId < 0 || nId > MAX_IMAGE)
	{
		return NULL;
	}

	if (m_pImage[nId])
	{
		return m_pImage[nId]->hImageDC;
	}

	return NULL;
}

BITMAP* CImageManager::GetBmpInfo(int nId)
{
	if (nId < 0 || nId > MAX_IMAGE)
	{
		return NULL;
	}

	if (m_pImage[nId])
	{
		return &m_pImage[nId]->bmpInfo;
	}

	return NULL;
}