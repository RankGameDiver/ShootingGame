#pragma once

#include "InGame.h"

class CFirstStage :
	public CInGame
{
public:
	CFirstStage(void);
	virtual ~CFirstStage(void);

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();
};
