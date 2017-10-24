#include "stdafx.h"

#define MAXENEMY 50

CEnemyManager::CEnemyManager()
{

}

CEnemyManager::~CEnemyManager()
{

}

void CEnemyManager::Initialize(CPlayerInfo* player)
{
	for (int i = 0; i < MAXENEMY; i++)
	{
		enemyList[i] = new CEnemy;
		enemyList[i]->Initialize(Vector2D(100, 100), player);
		enemyList[i]->SetActive(false);
	}
	m_player = player;
}

void CEnemyManager::Render()
{
	for (int i = 0; i < MAXENEMY; i++)
	{
		if (enemyList[i]->GetActive())
		{
			enemyList[i]->Render();
		}
	}
}

void CEnemyManager::Pulse()
{
	for (int i = 0; i < MAXENEMY; i++)
	{
		if (enemyList[i]->GetActive())
		{
			enemyList[i]->Pulse();
		}
	}
}

void CEnemyManager::Terminate()
{
	delete[] enemyList;
}

CEnemy* CEnemyManager::OnObject(int enemyType)
{
	for (int i = 0; i < MAXENEMY; i++)
	{
		if (!enemyList[i]->GetActive())
		{
			enemyList[i]->SetActive(true);
			enemyList[i]->SetEnemyType(enemyType);
			return enemyList[i];
		}
	}
}

CEnemy* CEnemyManager::SetAct(int temp, bool bIsActive)
{
	enemyList[temp]->SetActive(bIsActive);
	return NULL;
}

bool CEnemyManager::GetAct(int temp)
{
	if (enemyList[temp]->GetActive())
		return true;
	else
		return false;
}

CImageInfo* CEnemyManager::GetCollision(int temp)
{
	return enemyList[temp]->GetCollision();
}

void CEnemyManager::CrashBullet(int temp)
{
	enemyList[temp]->DecrementLife(m_player->GetDamage());
}
