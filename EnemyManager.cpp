#include "stdafx.h"

#define MAXENEMY 50

CEnemyManager::CEnemyManager()
{

}

CEnemyManager::~CEnemyManager()
{

}

void CEnemyManager::Initialize()
{
	for (int i = 0; i < MAXENEMY; i++)
	{
		enemyList[i] = new CEnemy;
		enemyList[i]->Initialize(0, Vector2D(100, 100));
		enemyList[i]->SetActive(false);
	}
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

CEnemy* CEnemyManager::OnObject()
{
	for (int i = 0; i < MAXENEMY; i++)
	{
		if (!enemyList[i]->GetActive())
		{
			enemyList[i]->SetActive(true);
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
	enemyList[temp]->DecrementLife();
}
