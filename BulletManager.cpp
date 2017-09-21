#include "stdafx.h"

#define MAXBULLET 200

CBulletManager::CBulletManager()
{

}

CBulletManager::~CBulletManager()
{

}

void CBulletManager::Initialize()
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

void CBulletManager::Pulse()
{
	for (int i = 0; i < MAXBULLET; i++)
	{
		if (bulletList[i]->GetActive())
		{
			bulletList[i]->Pulse();
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
