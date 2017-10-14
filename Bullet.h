#pragma once

class CBullet : public CBaseObject
{
protected:
	bool m_bIsActive = false; // 활성화
	const int damage = 1; // 데미지
	int m_type; // 총알 종류

public:
	CBullet();
	virtual ~CBullet();

public:
	__inline void SetActive(bool bActive); // 총알이 움직이는 상태면 true, 아니면 false
	__inline bool GetActive() const; // 현재 상태를 bool 값으로 반환
	
	__inline void SetBulletType(int bulletType); // 총알 종류를 설정
	__inline int GetBulletType(); // 총알 종류를 반환

	bool Initialize(Vector2D pos);
	void Terminate();
	bool Pulse(int bulletType);
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

__inline void CBullet::SetBulletType(int bulletType)
{
	m_type = bulletType;
}

__inline int CBullet::GetBulletType()
{
	return m_type;
}