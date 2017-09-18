#pragma once
#include "BaseRender.h"
class CBaseObject :	public CBaseRender // CBaseObject는 CBaseRender을 상속받는다
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

public:
	CBaseObject();
	virtual ~CBaseObject();

public:
	void SetUpCollision();
	__inline CImageInfo* GetCollision() { return &m_kCollision; };
	bool CheckCollision(Vector2D vPos);

public:
	bool Pulse();
};

