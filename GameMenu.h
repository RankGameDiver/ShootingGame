#pragma once

#include "InGame.h"

class CGameMenu :
	public CInGame
{
public:
	CGameMenu(void);
	virtual ~CGameMenu(void);

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();

};