#pragma once

class CBulletManager;

class CPlayerManager : public CSingleton<CPlayerManager>
{
private:
	CPlayerInfo* player;

public:
	CPlayerManager();
	~CPlayerManager();

public:
	void Initialize();
	void Render();
	void Pulse();
	void Terminate();

	CPlayerInfo* OnObject();
	CPlayerInfo* SetAct(bool bIsActive);
	bool GetAct();
	CImageInfo* GetCollision();
	void CrashBullet();
};

#define g_pPlayerManager	CPlayerManager::GetSingleton()