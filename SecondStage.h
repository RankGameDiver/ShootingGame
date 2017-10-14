#pragma once

#include "InGame.h"

class CSecondStage :
	public CInGame
{
public:
	CSecondStage(void);
	virtual ~CSecondStage(void);

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();
};
#pragma once
