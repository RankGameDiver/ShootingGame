#pragma once
#include "BaseObject.h"

class CEnemy : 
	public CBaseObject
{
public:
	enum eEnemyKind
	{
		eEnemyKind_Banana, // 바나나
		eEnemyKind_Owner, // 오너
		eEnemyKind_Rabbit, // 토끼
		eEnemyKind_Doll, // 인형
		eEnemyKind_Bean, // 콩
		eEnemyKind_WalnutDoll, // 호두까기
		eEnemyKind_Dog, // 강아지
		eEnemyKind_Purple, // 보라색
		eEnemyKind_Pumpkin, // 호박
	};
	eEnemyKind m_eEnemyKind;

protected:
	bool m_bIsActive; // 상태(죽었는지 살았는지)

	int m_nLife; // 몬스터 생명 수
	bool move;// true면 오른쪽으로 이동, false면 왼쪽으로 이동

	CBulletManager* bulletList;

public:
	CEnemy();
	virtual ~CEnemy();

public:
	_inline void SetActive(bool life); // 살아있으면 true, 죽으면 false(초기 생성시 true로 생성)
	_inline bool GetActive() const;

	_inline void SetLife(int hp); // 잡몹들은 모두 체력 3
	_inline void DecrementLife(); // 피격시 실행
	_inline int GetLife() const; // 현재 체력을 반환

	__inline D3DXVECTOR3 GetPos(); // 시작 위치 반환

	__inline D3DXVECTOR3 GetScale(); // 시작 위치 반환

	bool Initialize(int m_eEnemyKind, Vector2D pos); // 초기 설정
	void Terminate(); // 제거
	bool Pulse(); // 매 프레임
	void Render(); // 화면에 그림
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

__inline D3DXVECTOR3 CEnemy::GetPos() // 시작 위치 반환
{
	return m_vPos;
}

__inline D3DXVECTOR3 CEnemy::GetScale() // 시작 위치 반환
{
	return m_vPos;
}

