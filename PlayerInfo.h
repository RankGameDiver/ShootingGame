#pragma once
#include "BaseObject.h"
#include "InputHandler.h"

class CBulletManager;

class CPlayerInfo :	public CBaseObject,
					public IInputHandler
					
{
protected:
	bool m_bIsActive; // �����̰� �ִ��� Ȯ��

	bool m_bIsPressEsc; // ESCŰ
	bool m_bIsPressLeft; // ���� ȭ��ǥ
	bool m_bIsPressRight; // ������ ȭ��ǥ
	bool m_bIsPressUp; // ���� ȭ��ǥ
	bool m_bIsPressDown; // �Ʒ��� ȭ��ǥ
	bool m_bIsPressZ; // ZŰ

	CBulletManager* bulletList;

	int m_nLife; // �÷��̾� ����
	int m_damage; // �÷��̾� ���ݷ�
	int m_delay; // �÷��̾� ���� ������
	int tempDelay;
	int applyTime;
	bool m_fastMode; // ���� ���� ����

public:
	CPlayerInfo();
	virtual ~CPlayerInfo();

public:
	__inline void SetActive(bool bActive); // ��������� true ������ false
	__inline bool GetActive() const; // ���� ���¸� bool������ ��ȯ

	// ���� ����
	__inline void IncrementLife(); // ���� ����
	__inline void DecrementLife(); // ���� ����
	__inline void SetLife(int m_life); // ���� ����
	__inline int GetLife() const; // ���� ���� �� ��ȯ
	//

	__inline void IncrementDamage(); // ���ݷ� ����
	__inline void SetDamage(int m_damage); // ���ݷ� ����
	__inline int GetDamage() const; // ���� ���ݷ� ��ȯ
	__inline CPlayerInfo* GetPlayer(); // ���� �÷��̾� ��ȯ

	__inline void FastAttack();
	__inline void SetAttackDelay(int delay);
	__inline int GetAttackDelay() const;

	bool Initialize(); // �ʱ� ����
	void Terminate(); // ����
	bool Pulse(); // �� ������
	void Render(); // ȭ�鿡 �׸�

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

__inline void CPlayerInfo::IncrementLife() // ���� �ϳ� �߰�
{
	m_nLife++;
	if (m_nLife > MAX_PLAYER_LIFE) { m_nLife = MAX_PLAYER_LIFE; }
}
__inline void CPlayerInfo::DecrementLife() // ���� �ϳ� ����
{
	m_nLife--;
}
__inline void CPlayerInfo::SetLife(int life) // ���� ���� ����
{
	m_nLife = life;
}
__inline int CPlayerInfo::GetLife() const // ���� ������ ���� ����
{
	return m_nLife;
}

__inline void CPlayerInfo::IncrementDamage() // ������ 1 ����
{
	m_damage++;
}
__inline void CPlayerInfo::SetDamage(int damage) // ������ ����
{
	m_damage = damage;
}
__inline int CPlayerInfo::GetDamage() const // ���� �������� ����
{
	return m_damage;
}

__inline void CPlayerInfo::FastAttack() // ���� ����
{
	m_fastMode = true;
}
__inline void CPlayerInfo::SetAttackDelay(int delay) // ���� ����
{
	m_delay = delay;
}
__inline int CPlayerInfo::GetAttackDelay() const // ���� ������ ����
{
	return m_delay;
}

__inline CPlayerInfo* CPlayerInfo::GetPlayer()
{
	return this;
}
