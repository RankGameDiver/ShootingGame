#pragma once

class CImageInfo : public RECT
{
public:
	SIZE m_siSize;

public:
	CImageInfo(void);
	virtual ~CImageInfo(void);
	CImageInfo(CImageInfo& rObj);
	CImageInfo(int x, int y, int w, int h);

	void operator = (CImageInfo& rObj);
	void operator = (RECT& rObj);
	void operator += (int iOffset);

	__inline void SetRect(int x, int y, int w, int h);
	__inline SIZE GetSize() const;
};

__inline void CImageInfo::SetRect(int x, int y, int w, int h)
{
	left = x;
	top = y;
	right = x + w;
	bottom = y + h;

	m_siSize.cx = w;
	m_siSize.cy = h;
}

__inline SIZE CImageInfo::GetSize() const
{
	return m_siSize;
}

