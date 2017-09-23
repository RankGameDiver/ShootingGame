#pragma once
#include "BaseRender.h"
class CBaseObject :	public CBaseRender,
					public CTimeManager,
					public CFrameSkip
{
protected:
	SIZE m_siCollision;
	POINT m_ptCollisionOffset; // 콜라이더 중심점

	CImageInfo m_kCollision;
	CImageInfo* m_pImageInfo;

public:
	CBaseObject();
	virtual ~CBaseObject();

public:
	void SetUpCollision();
	bool CheckCollision(Vector2D vPos);
	bool CheckCollision(CImageInfo* collision1, CImageInfo* collsion2);
	__inline CImageInfo* GetCollision() { return &m_kCollision; };
	__inline Vector2D GetCollision(Vector2D vPos) {	return vPos; }

public:
	bool Pulse();
};

