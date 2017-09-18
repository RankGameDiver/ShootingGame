#pragma once

#include "IScene.h"
#include "BaseRender.h"

class CInGame :
	public CBaseRender,
	public IScene
{
private:
	float	m_fTime;

	CPlayerInfo*	m_pPlayer;
	CEnemy*	m_eEnemy;

public:
	CInGame(void);
	virtual ~CInGame(void);

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();
};
