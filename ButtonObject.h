#pragma once
#include "BaseObject.h"
class CButtonObject :
	public CBaseObject
{
public:
	CButtonObject();
	virtual ~CButtonObject();

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();
};

