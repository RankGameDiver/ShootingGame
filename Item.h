#pragma once

class CItem : public CBaseObject
{
protected:
	bool m_bIsActive = false; // 활성화
	int m_type; // 아이템 종류

public:
	CItem();
	virtual ~CItem();

public:
	__inline void SetActive(bool bActive); // 움직이는 상태면 true, 아니면 false
	__inline bool GetActive() const; // 현재 상태를 bool 값으로 반환

	__inline void SetItemType(int itemType); // 아이템 종류를 설정
	__inline int GetItemType(); // 아이템 종류를 반환

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