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
	int attackDelay;

public:
	CPlayerInfo();
	virtual ~CPlayerInfo();

public:
	__inline void SetActive(bool bActive); // ��������� true ������ false
	__inline bool GetActive() const; // ���� ���¸� bool������ ��ȯ

	// ���� ����
	__inline void IncrementLife();
	__inline void DecrementLife();
	__inline void SetLife(int iLife);
	__inline int GetLife() const;
	//

	__inline CPlayerInfo* GetPlayer();

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
}
__inline void CPlayerInfo::DecrementLife() // ���� �ϳ� ����
{
	m_nLife--;
}
__inline void CPlayerInfo::SetLife(int nLife) // ���� ���� ����
{
	m_nLife = nLife;
}
__inline int CPlayerInfo::GetLife() const // ���� ������ ���� ����
{
	return m_nLife;
}

__inline CPlayerInfo* CPlayerInfo::GetPlayer()
{
	return this;
}
