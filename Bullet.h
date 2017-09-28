#pragma once

class CBullet : public CBaseObject
{
protected:
	bool m_bIsActive = false; // Ȱ��ȭ
	const int damage = 1; // ������

public:
	CBullet();
	virtual ~CBullet();

public:
	__inline void SetActive(bool bActive); // �Ѿ��� �����̴� ���¸� true, �ƴϸ� false
	__inline bool GetActive() const; // ���� ���¸� bool ������ ��ȯ
	
	bool Initialize(int m_eEnemyKind,Vector2D pos);
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