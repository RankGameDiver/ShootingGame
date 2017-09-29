#pragma once

//class CBulletManager;

class CEnemyManager : public CSingleton<CEnemyManager>
{
private:
	CEnemy* enemyList[50];

public:
	CEnemyManager();
	~CEnemyManager();

public:
	void Initialize(CPlayerInfo* player);
	void Render();
	void Pulse();
	void Terminate();

	CEnemy* OnObject();
	CEnemy* SetAct(int temp, bool bIsActive);
	CPlayerInfo* m_player;
	bool GetAct(int temp);
	CImageInfo* GetCollision(int temp);
	void CrashBullet(int temp);
};

#define g_pEnemyManager	CEnemyManager::GetSingleton()