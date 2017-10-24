#pragma once

class CItem : public CBaseObject
{
protected:
	bool m_bIsActive = false; // Ȱ��ȭ
	int m_type; // ������ ����

public:
	CItem();
	virtual ~CItem();

public:
	__inline void SetActive(bool bActive); // �����̴� ���¸� true, �ƴϸ� false
	__inline bool GetActive() const; // ���� ���¸� bool ������ ��ȯ

	__inline void SetItemType(int itemType); // ������ ������ ����
	__inline int GetItemType(); // ������ ������ ��ȯ

	bool Initialize(Vector2D pos);
	void Terminate();
	bool Pulse(int itemType);
	void Render();
};

__inline void CItem::SetActive(bool bActive)
{
	m_bIsActive = bActive;
}

__inline bool CItem::GetActive() const
{
	return m_bIsActive;
}

__inline void CItem::SetItemType(int itemType)
{
	m_type = itemType;
}

__inline int CItem::GetItemType()
{
	return m_type;
}