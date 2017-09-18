#pragma once

#include "IScene.h"
#include "BaseRender.h"

class CMenu :
	public CBaseRender,
	public IScene
{
private:
	float	m_fTime;

public:
	CMenu(void);
	virtual ~CMenu(void);

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();
};
