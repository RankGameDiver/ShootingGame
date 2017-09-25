#include "stdafx.h"

CPlayerManager::CPlayerManager()
{

}

CPlayerManager::~CPlayerManager()
{

}

void CPlayerManager::Initialize()
{
		player = new CPlayerInfo;
		player->Initialize();
		player->SetActive(false);
		g_pInputManager->SetInputHandler(player);
}

void CPlayerManager::Render()
{
	if (player->GetActive())
	{
		player->Render();
	}
}

void CPlayerManager::Pulse()
{
	if (player->GetActive())
	{
		player->Pulse();
	}
}

void CPlayerManager::Terminate()
{
	delete player;
}

CPlayerInfo* CPlayerManager::OnObject()
{
	if (!player->GetActive())
	{
		player->SetActive(true);
		return player;
	}
}

CPlayerInfo* CPlayerManager::SetAct(bool bIsActive)
{
	player->SetActive(bIsActive);
	return NULL;
}

bool CPlayerManager::GetAct()
{
	if (player->GetActive())
		return true;
	else
		return false;
}

CImageInfo* CPlayerManager::GetCollision()
{
	return player->GetCollision();
}

void CPlayerManager::CrashBullet()
{
	player->DecrementLife();
}
