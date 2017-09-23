#pragma once

class CBulletManager;

class CEnemyManager : public CSingleton<CEnemyManager>
{
private:
	CEnemy* enemyList[50];

public:
	CEnemyManager();
	~CEnemyManager();

public:
	void Initialize(int enemyType, Vector2D pos);
	void Render();
	void Pulse();
	void Terminate();

	CEnemy* OnObject();
	bool GetAct(int temp);
	CImageInfo* GetCollision(int temp);
};

#define g_pEnemyManager	CEnemyManager::GetSingleton()