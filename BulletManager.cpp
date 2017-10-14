#include "stdafx.h"

#define MAXBULLET 50

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
	bulletCount = 0;
}

void CBulletManager::Init(CPlayerInfo* player)
{
	for (int i = 0; i < MAXBULLET; i++)
	{
		bulletList[i] = new CBullet;
		bulletList[i]->Initialize(0, Vector2D(-100, -100));
		bulletList[i]->SetActive(false);
	}
	bulletCount = 0;
	m_player = player->GetPlayer();
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
			bulletCount++;
			return bulletList[i];
		}
	}
}

CImageInfo* CBulletManager::CheckCol(bool bulletType) // false는 플레이어 탄환, true는 몬스터 탄환
{
	for (int i = 0; i < bulletCount; i++)
	{
		if (bulletList[i]->GetActive())
		{
			for (int j = 0; j < 50; j++)
			{
				if (g_pEnemyManager->GetAct(j))
				{
					if (!bulletType && CBaseObject::CheckCollision(bulletList[i]->GetCollision(), g_pEnemyManager->GetCollision(j)))
					{
						bulletList[i]->SetActive(false);
						g_pEnemyManager->CrashBullet(j);
						bulletCount--;
					}
					else if (bulletType && CBaseObject::CheckCollision(bulletList[i]->GetCollision(), m_player->GetCollision()))
					{
						bulletList[i]->SetActive(false);
						m_player->DecrementLife();
						bulletCount--;
					}
					else {}
				}
			}
		}
	}
	return NULL;
}

void CBulletManager::DelBullet()
{
	bulletCount--;
}
