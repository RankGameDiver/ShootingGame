#pragma once
#include "BaseObject.h"

class CBananaInfo : public CBaseObject
{
protected:
	D3DVECTOR m_vPos; // 위치
	D3DVECTOR m_vScale; // 크기
	bool m_bIsActive; // 상태(죽었는지 살았는지)

	int m_nLife; // 몬스터 생명 수

public:
	CBananaInfo();
	virtual ~CBananaInfo();

public:
	_inline void SetActive(bool life); // 살아있으면 true, 죽으면 false(초기 생성시 true로 생성)
	_inline bool IsActive() const;

	_inline void SetLife(int hp); // 잡몹들은 모두 체력 3
	_inline void DecrementLife(); // 피격시 실행
	_inline int GetLife() const; // 현재 체력을 반환

	__inline void SetPos(); // 시작 위치 지정

	__inline D3DXVECTOR3 GetPos(); // 시작 위치 반환

	__inline void SetScale(); // 크기 지정 // 미완성

	__inline D3DXVECTOR3 GetScale(); // 시작 위치 반환

	bool Initialize(); // 초기 설정
	void Terminate(); // 제거
	bool Pulse(); // 매 프레임
	void Render(); // 화면에 그림
};

_inline void CBananaInfo::SetActive(bool life)
{
	m_bIsActive = life;
}

_inline bool CBananaInfo::IsActive() const
{
	return m_bIsActive;
}

_inline void CBananaInfo::SetLife(int hp)
{
	m_nLife = hp;
}

_inline void CBananaInfo::DecrementLife()
{
	m_nLife--;
}

_inline int CBananaInfo::GetLife() const
{
	return m_nLife;
}

__inline void CBananaInfo::SetPos() // 시작 위치 지정
{
	m_vPos.x = 100;
	m_vPos.y = 100;
}
__inline D3DXVECTOR3 CBananaInfo::GetPos() // 시작 위치 반환
{
	return m_vPos;
}
__inline void CBananaInfo::SetScale() // 크기 지정
{
	m_vScale.x = 1.5f;
	m_vScale.y = 1.5f;
	m_vScale.z = 1.0f;
}
__inline D3DXVECTOR3 CBananaInfo::GetScale() // 시작 위치 반환
{
	return m_vPos;
}

