#pragma once

class CEnemyManager;

class CBulletManager : public CSingleton<CBulletManager>,
	public CBaseObject
{
private:
	CBullet* bulletList[200];

public:
	CBulletManager();
	~CBulletManager();

public:
	void Init(); // Initualize
	void Render();
	void Frame(); // Pulse
	void Terminate();

	CBullet* OnObject();
	CImageInfo* GetCollision();
};

#define g_pBulletManager	CBulletManager::GetSingleton()