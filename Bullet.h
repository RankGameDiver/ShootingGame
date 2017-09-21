#pragma once
#include "BaseObject.h"

class CPlayerInfo;

class CBullet : public CBaseObject
{
protected:
	bool m_bIsActive; // 활성화
	CPlayerInfo* m_pPlayer;
	const int damage = 1; // 데미지

public:
	CBullet();
	virtual ~CBullet();

public:
	__inline void SetActive(bool bActive); // 총알이 움직이는 상태면 true, 아니면 false
	__inline bool IsActive() const; // 현재 상태를 bool 값으로 반환
	
	__inline void CrashBullet();
	
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();
};

__inline void CBullet::SetActive(bool bActive)
{
	m_bIsActive = bActive;
}

__inline bool CBullet::IsActive() const
{
	return m_bIsActive;
}

__inline void CBullet::CrashBullet() // 총알 충돌 (미완성)
{

}