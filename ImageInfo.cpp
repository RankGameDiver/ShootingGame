#include "StdAfx.h"
#include "ImageInfo.h"


CImageInfo::CImageInfo(void)
{
}


CImageInfo::~CImageInfo(void)
{
}

CImageInfo::CImageInfo(CImageInfo& rObj)
{
	left = rObj.left;
	top = rObj.top;
	right = rObj.right;
	bottom = rObj.bottom;

	m_siSize.cx = rObj.m_siSize.cx;
	m_siSize.cy = rObj.m_siSize.cy;
}

CImageInfo::CImageInfo(int x, int y, int w, int h)
{
	SetRect(x, y, w, h);
}

void CImageInfo::operator = (CImageInfo& rObj)
{
	left = rObj.left;
	top = rObj.top;
	right = rObj.right;
	bottom = rObj.bottom;

	m_siSize.cx = rObj.m_siSize.cx;
	m_siSize.cy = rObj.m_siSize.cy;
}

void CImageInfo::operator = (RECT& rObj)
{
	left = rObj.left;
	top = rObj.top;
	right = rObj.right;
	bottom = rObj.bottom;

	m_siSize.cx = rObj.right - rObj.left;
	m_siSize.cy = rObj.bottom - rObj.top;
}

void CImageInfo::operator += (int iOffset)
{
	left += iOffset;
	top += iOffset;
	right += iOffset;
	bottom += iOffset;

	m_siSize.cx += iOffset;
	m_siSize.cy += iOffset;
}