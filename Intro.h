#pragma once

#include "IScene.h"
#include "BaseRender.h"

class CIntro :
	public CBaseRender,
	public IScene
{
private:
	float	m_fTime;

public:
	CIntro(void);
	virtual ~CIntro(void);

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();
};