#pragma once
#include "BaseObject.h"

class CEnemy : 
	public CBaseObject
{
public:
	enum eEnemyKind
	{
		eEnemyKind_Banana, // �ٳ���
		eEnemyKind_Owner, // ����
		eEnemyKind_Rabbit, // �䳢
		eEnemyKind_Doll, // ����
		eEnemyKind_Bean, // ��
		eEnemyKind_WalnutDoll, // ȣ�α��
		eEnemyKind_Dog, // ������
		eEnemyKind_Purple, // �����
		eEnemyKind_Pumpkin, // ȣ��
	};
	eEnemyKind m_eEnemyKind;

protected:
	bool m_bIsActive; // ����(�׾����� ��Ҵ���)

	int m_nLife; // ���� ���� ��
	bool move;// true�� ���������� �̵�, false�� �������� �̵�

	CBulletManager* bulletList;

public:
	CEnemy();
	virtual ~CEnemy();

public:
	_inline void SetActive(bool life); // ��������� true, ������ false(�ʱ� ������ true�� ����)
	_inline bool GetActive() const;

	_inline void SetLife(int hp); // ������� ��� ü�� 3
	_inline void DecrementLife(); // �ǰݽ� ����
	_inline int GetLife() const; // ���� ü���� ��ȯ

	__inline D3DXVECTOR3 GetPos(); // ���� ��ġ ��ȯ

	__inline D3DXVECTOR3 GetScale(); // ���� ��ġ ��ȯ

	bool Initialize(int m_eEnemyKind, Vector2D pos); // �ʱ� ����
	void Terminate(); // ����
	bool Pulse(); // �� ������
	void Render(); // ȭ�鿡 �׸�
};

_inline void CEnemy::SetActive(bool life)
{
	m_bIsActive = life;
}

_inline bool CEnemy::GetActive() const
{
	return m_bIsActive;
}

_inline void CEnemy::SetLife(int hp)
{
	m_nLife = hp;
}

_inline void CEnemy::DecrementLife()
{
	m_nLife--;
}

_inline int CEnemy::GetLife() const
{
	return m_nLife;
}

__inline D3DXVECTOR3 CEnemy::GetPos() // ���� ��ġ ��ȯ
{
	return m_vPos;
}

__inline D3DXVECTOR3 CEnemy::GetScale() // ���� ��ġ ��ȯ
{
	return m_vPos;
}

