#pragma once

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

	CPlayerInfo* m_player;
	CEnemy* OnObject(int enemyType);
	CEnemy* SetAct(int temp, bool bIsActive);
	bool GetAct(int temp);

	CImageInfo* GetCollision(int temp);
	void CrashBullet(int temp);
};

#define g_pEnemyManager	CEnemyManager::GetSingleton()