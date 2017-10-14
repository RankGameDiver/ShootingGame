#pragma once

#include "InGame.h"

class CThirdStage :
	public CInGame
{
public:
	CThirdStage(void);
	virtual ~CThirdStage(void);

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();
};
