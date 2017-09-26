#pragma once

class CInGame: public CSingleton<CInGame>,
	public CBaseObject,
	public IScene
{
public:
	float			m_fTime;
	CBackGround*	m_pBackGround;
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
