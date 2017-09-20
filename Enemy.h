#pragma once
#include "BaseObject.h"

class CEnemy : 
	public CBaseObject
{
protected:
	D3DVECTOR m_vPos; // ��ġ
	D3DVECTOR m_vScale; // ũ��
	bool m_bIsActive; // ����(�׾����� ��Ҵ���)

	int m_nLife; // ���� ���� ��

	CFrameSkip*		m_pGameFrame;

public:
	CEnemy();
	virtual ~CEnemy();

public:
	_inline void SetActive(bool life); // ��������� true, ������ false(�ʱ� ������ true�� ����)
	_inline bool IsActive() const;

	_inline void SetLife(int hp); // ������� ��� ü�� 3
	_inline void DecrementLife(); // �ǰݽ� ����
	_inline int GetLife() const; // ���� ü���� ��ȯ

	__inline void SetPos(); // ���� ��ġ ����

	__inline D3DXVECTOR3 GetPos(); // ���� ��ġ ��ȯ

	__inline void SetScale(); // ũ�� ���� // �̿ϼ�

	__inline D3DXVECTOR3 GetScale(); // ���� ��ġ ��ȯ

	bool Initialize(eEnemyKind m_eEnemyKind); // �ʱ� ����
	void Terminate(); // ����
	bool Pulse(); // �� ������
	void Render(); // ȭ�鿡 �׸�
};

_inline void CEnemy::SetActive(bool life)
{
	m_bIsActive = life;
}

_inline bool CEnemy::IsActive() const
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

__inline void CEnemy::SetPos() // ���� ��ġ ����
{
	m_vPos.x = 100;
	m_vPos.y = 100;
}
__inline D3DXVECTOR3 CEnemy::GetPos() // ���� ��ġ ��ȯ
{
	return m_vPos;
}
__inline void CEnemy::SetScale() // ũ�� ����
{
	m_vScale.x = 1.0f;
	m_vScale.y = 1.0f;
	m_vScale.z = 1.0f;
}
__inline D3DXVECTOR3 CEnemy::GetScale() // ���� ��ġ ��ȯ
{
	return m_vPos;
}

