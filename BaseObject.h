#pragma once
#include "BaseRender.h"
class CBaseObject :	public CBaseRender,
					public CTimeManager,
					public CFrameSkip
{
public:
	enum eActionState
	{
		eActionState_Unknown,
		eActionState_Normal,
		eActionState_Left,
		eActionState_Right,
		eActionState_Up,
		eActionState_Down,
	};

protected:
	eActionState m_eActionState;

	SIZE m_siCollision;
	POINT m_ptCollisionOffset; // 콜라이더 중심점

	CImageInfo m_kCollision;
	CImageInfo* m_pImageInfo;
	CImageInfo* m_eImageInfo;

public:
	CBaseObject();
	virtual ~CBaseObject();

public:
	void SetUpCollision();
	__inline CImageInfo* GetCollision() { return &m_kCollision; };
	bool CheckCollision(Vector2D vPos);
	bool CheckCollision(CImageInfo* collision);
	__inline Vector2D GetCollision(Vector2D vPos) {	return vPos; }

public:
	bool Pulse();
};

