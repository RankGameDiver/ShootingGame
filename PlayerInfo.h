#pragma once
#include "BaseObject.h"
#include "InputHandler.h"

class CEnemy;

class CPlayerInfo : public CBaseObject, // PlayerInfo(플레이어 정보)는 BaseObject와 IInputHandler를 상속받고 있다
					public IInputHandler
{
protected:
	bool m_bIsActive; // 움직이고 있는지 확인

	bool m_bIsPressEsc; // ESC키
	bool m_bIsPressLeft; // 왼쪽 화살표
	bool m_bIsPressRight; // 오른쪽 화살표
	bool m_bIsPressUp; // 위쪽 화살표
	bool m_bIsPressDown; // 아래쪽 화살표

	CFrameSkip*		m_pGameFrame;

	int m_nLife; // 플레이어 생명

public:
	CPlayerInfo();
	virtual ~CPlayerInfo();

public:
	__inline void SetActive(bool bActive); // 살아있으면 true 죽으면 false
	__inline bool IsActive() const; // 현재 상태를 bool값으로 반환

	// 생명 관련
	__inline void IncrementLife();
	__inline void DecrementLife();
	__inline void SetLife(int iLife);
	__inline int GetLife() const;
	//

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
__inline bool CPlayerInfo::IsActive() const
{
	return m_bIsActive;
}
__inline void CPlayerInfo::IncrementLife() // 생명 하나 추가
{
	m_nLife++;
}
__inline void CPlayerInfo::DecrementLife() // 생명 하나 잃음
{
	m_nLife--;
}
__inline void CPlayerInfo::SetLife(int nLife) // 생명 갯수 설정
{
	m_nLife = nLife;
}
__inline int CPlayerInfo::GetLife() const // 현재 생명의 수를 리턴
{
	return m_nLife;
}