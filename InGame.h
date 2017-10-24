#pragma once

class CInGame: public CSingleton<CInGame>,
	public CBaseObject,
	public IScene
{
public:
	float			m_fTime;
	CBackGround*	m_pBackGroundA;
	CBackGround*	m_pBackGroundB;
	CBackGround*	m_pBackGround2;
	CPlayerInfo*	m_pPlayer;
	CEnemyManager*	m_pEnemyManager;
	CBulletManager* m_pBulletManager;

public:
	CInGame(void);
	virtual ~CInGame(void);

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();
};

#define g_pInGame	CInGame::GetSingleton()
