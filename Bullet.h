#pragma once
class CPlayerInfo;

class CBullet : public CBaseObject
{
protected:
	bool m_bIsActive = false; // 활성화
	CPlayerInfo*	m_pPlayer;
	CFrameSkip*		m_pGameFrame;
	const int damage = 1; // 데미지

public:
	CBullet();
	virtual ~CBullet();

public:
	__inline void SetActive(bool bActive); // 총알이 움직이는 상태면 true, 아니면 false
	__inline bool GetActive() const; // 현재 상태를 bool 값으로 반환
	
	bool Initialize(Vector2D pos);
	void Terminate();
	bool Pulse();
	void Render();
};

__inline void CBullet::SetActive(bool bActive)
{
	m_bIsActive = bActive;
}

__inline bool CBullet::GetActive() const
{
	return m_bIsActive;
}