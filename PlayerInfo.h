#pragma once
#include "BaseObject.h"
#include "InputHandler.h"

class CBulletManager;

class CPlayerInfo :	public CBaseObject,
					public IInputHandler
					
{
protected:
	bool m_bIsActive; // 움직이고 있는지 확인

	bool m_bIsPressEsc; // ESC키
	bool m_bIsPressLeft; // 왼쪽 화살표
	bool m_bIsPressRight; // 오른쪽 화살표
	bool m_bIsPressUp; // 위쪽 화살표
	bool m_bIsPressDown; // 아래쪽 화살표
	bool m_bIsPressZ; // Z키

	CBulletManager* bulletList;

	int m_nLife; // 플레이어 생명
	int m_damage; // 플레이어 공격력
	int m_delay; // 플레이어 공속 딜레이
	int tempDelay;
	int applyTime;
	bool m_fastMode; // 공속 버프 적용

public:
	CPlayerInfo();
	virtual ~CPlayerInfo();

public:
	__inline void SetActive(bool bActive); // 살아있으면 true 죽으면 false
	__inline bool GetActive() const; // 현재 상태를 bool값으로 반환

	// 생명 관련
	__inline void IncrementLife(); // 생명 증가
	__inline void DecrementLife(); // 생명 감소
	__inline void SetLife(int m_life); // 생명 설정
	__inline int GetLife() const; // 현재 생명 수 반환
	//

	__inline void IncrementDamage(); // 공격력 증가
	__inline void SetDamage(int m_damage); // 공격력 설정
	__inline int GetDamage() const; // 현재 공격력 반환
	__inline CPlayerInfo* GetPlayer(); // 현재 플레이어 반환

	__inline void FastAttack();
	__inline void SetAttackDelay(int delay);
	__inline int GetAttackDelay() const;

	bool Initialize(); // 초기 설정
	void Terminate(); // 제거
	bool Pulse(); // 매 프레임
	void Render(); // 화면에 그림

public:
	void KeyboardHandler(void);
	void MouseHandler(MOUSESTATE diMouseState);

};

__inline void CPlayerInfo::SetActive(bool bActive)
{
	m_bIsActive = bActive;
}
__inline bool CPlayerInfo::GetActive() const
{
	return m_bIsActive;
}

__inline void CPlayerInfo::IncrementLife() // 생명 하나 추가
{
	m_nLife++;
	if (m_nLife > MAX_PLAYER_LIFE) { m_nLife = MAX_PLAYER_LIFE; }
}
__inline void CPlayerInfo::DecrementLife() // 생명 하나 잃음
{
	m_nLife--;
}
__inline void CPlayerInfo::SetLife(int life) // 생명 갯수 설정
{
	m_nLife = life;
}
__inline int CPlayerInfo::GetLife() const // 현재 생명의 수를 리턴
{
	return m_nLife;
}

__inline void CPlayerInfo::IncrementDamage() // 데미지 1 증가
{
	m_damage++;
}
__inline void CPlayerInfo::SetDamage(int damage) // 데미지 설정
{
	m_damage = damage;
}
__inline int CPlayerInfo::GetDamage() const // 현재 데미지를 리턴
{
	return m_damage;
}

__inline void CPlayerInfo::FastAttack() // 공속 증가
{
	m_fastMode = true;
}
__inline void CPlayerInfo::SetAttackDelay(int delay) // 공속 설정
{
	m_delay = delay;
}
__inline int CPlayerInfo::GetAttackDelay() const // 현재 공속을 리턴
{
	return m_delay;
}

__inline CPlayerInfo* CPlayerInfo::GetPlayer()
{
	return this;
}
