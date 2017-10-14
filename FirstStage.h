#pragma once

#include "InGame.h"

class CFirstStage :
	public CInGame, public IInputHandler
{
public:
	CFirstStage(void);
	virtual ~CFirstStage(void);

private:
	bool m_bIsMouseLeft;
	bool m_bIsMouseRight;

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();

public:
	void KeyboardHandler(void);
	void MouseHandler(MOUSESTATE diMouseState);

};
