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
		bulletList[i]->Initialize(Vector2D(0, 0));
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

void CBulletManager::Frame()
{
	for (int i = 0; i < MAXBULLET; i++)
	{
		if (bulletList[i]->GetActive())
		{
			bulletList[i]->Pulse();
			CBulletManager::GetCollision();
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

CImageInfo* CBulletManager::GetCollision()
{
	for (int i = 0; i < MAXBULLET; i++)
	{
		if (bulletList[i]->GetActive())
		{
			for (int j = 0; j < 50; j++)
			{
				if (CBaseObject::CheckCollision(bulletList[i]->GetCollision(), g_pEnemyManager->GetCollision(j)))
				{
					bulletList[i]->SetActive(false);
				}
			}
		}
	}
	return NULL;
}
