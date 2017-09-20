#pragma once

#include "IScene.h"
#include "BaseRender.h"

class CInGame :
	public CBaseRender,
	public IScene
{
public:
	float	m_fTime;
	CBackGround* m_pBackGround;
	CPlayerInfo*	m_pPlayer;
	CEnemy*	m_pEnemy;

public:
	CInGame(void);
	virtual ~CInGame(void);

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();
};
