#pragma once

class CBullet : public CBaseObject
{
protected:
	bool m_bIsActive = false; // Ȱ��ȭ
	const int damage = 1; // ������
	int m_type; // �Ѿ� ����

public:
	CBullet();
	virtual ~CBullet();

public:
	__inline void SetActive(bool bActive); // �Ѿ��� �����̴� ���¸� true, �ƴϸ� false
	__inline bool GetActive() const; // ���� ���¸� bool ������ ��ȯ
	
	__inline void SetBulletType(int bulletType); // �Ѿ� ������ ����
	__inline int GetBulletType(); // �Ѿ� ������ ��ȯ

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