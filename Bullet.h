#pragma once
class CPlayerInfo;

class CBullet : public CBaseObject
{
protected:
	bool m_bIsActive; // Ȱ��ȭ
	CPlayerInfo* m_pPlayer;
	CFrameSkip*		m_pGameFrame;
	const int damage = 1; // ������

public:
	CBullet();
	virtual ~CBullet();

public:
	__inline void SetActive(bool bActive); // �Ѿ��� �����̴� ���¸� true, �ƴϸ� false
	__inline bool GetActive() const; // ���� ���¸� bool ������ ��ȯ
	
	__inline void CrashBullet();
	
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

__inline void CBullet::CrashBullet() // �Ѿ� �浹 (�̿ϼ�)
{

}