#include "stdafx.h"

#define MAXBULLET 200

CBulletManager::CBulletManager()
{

}

CBulletManager::~CBulletManager()
{

}

void CBulletManager::Init()
{
	for (int i = 0; i < MAXBULLET; i++)
	{
		bulletList[i] = new CBullet;
		bulletList[i]->Initialize(0, Vector2D(-100, -100));
		bulletList[i]->SetActive(false);
	}
}

void CBulletManager::Render()
{
	for (int i = 0; i < MAXBULLET; i++)
	{
		if (bulletList[i]->GetActive())
		{
			bulletList[i]->Render();
		}
	}
}

void CBulletManager::Frame(int bulletType)
{
	for (int i = 0; i < MAXBULLET; i++)
	{
		if (bulletList[i]->GetActive())
		{
			bulletList[i]->Pulse(bulletType);
			CBulletManager::CheckCol(bulletType);
		}
	}
}

void CBulletManager::Terminate()
{
	delete[] bulletList;
}

CBullet* CBulletManager::OnObject()
{
	for (int i = 0; i < MAXBULLET; i++)
	{
		if (!bulletList[i]->GetActive())
		{
			bulletList[i]->SetActive(true);
			return bulletList[i];
		}
	}
}

CImageInfo* CBulletManager::CheckCol(bool bulletType) // false는 플레이어 탄환, true는 몬스터 탄환
{
	for (int i = 0; i < MAXBULLET; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (bulletList[i]->GetActive() && g_pEnemyManager->GetAct(j) || g_pPlayerManager->GetAct())
			{
				if (bulletType && CBaseObject::CheckCollision(bulletList[i]->GetCollision(), g_pPlayerManager->GetCollision())) // 몬스터 탄환 판정 미완성
				{
					bulletList[i]->SetActive(false);
					g_pPlayerManager->CrashBullet();
				}
				else if (!bulletType && CBaseObject::CheckCollision(bulletList[i]->GetCollision(), g_pEnemyManager->GetCollision(j)))
				{
					bulletList[i]->SetActive(false);
					g_pEnemyManager->CrashBullet(j);
				}
				else {}
			}
		}
	}
	return NULL;
}
