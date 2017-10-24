#include "stdafx.h"

CItemManager::CItemManager()
{

}

CItemManager::~CItemManager()
{

}

void CItemManager::Init()
{
		item = new CItem;
		item->Initialize(Vector2D(-100, -100));
		item->SetActive(false);
}

void CItemManager::Init(CPlayerInfo* player)
{
	item = new CItem;
	item->Initialize(Vector2D(-100, -100));
	item->SetActive(false);
	m_player = player->GetPlayer();
}

void CItemManager::Render()
{
	if (item->GetActive())	item->Render();
}

void CItemManager::Frame(int bulletType)
{
	if (item->GetActive())
	{
		item->Pulse(bulletType);
		CItemManager::CheckCol(bulletType);
	}
}

void CItemManager::Terminate()
{
	delete item;
}

CItem* CItemManager::OnObject(int itemType)
{
	if (!item->GetActive())
	{
		item->SetActive(true);
		item->SetItemType(itemType);
		return item;
	}
}

CItem* CItemManager::SetAct(bool bIsActive)
{
	item->SetActive(bIsActive);
	return NULL;
}

bool CItemManager::GetAct()
{
	if (item->GetActive())
		return true;
	else
		return false;
}


CImageInfo* CItemManager::CheckCol(bool bulletType) // false는 플레이어 탄환, true는 몬스터 탄환
{
	if (item->GetActive())
	{
		if (CBaseObject::CheckCollision(item->GetCollision(), m_player->GetCollision()))
		{
			item->SetActive(false);
			switch (item->GetItemType())
			{
			case 0: // 공격력 증가
				m_player->IncrementDamage();
				break;
			case 1: // 체력 회복
				m_player->IncrementLife();
				break;
			case 2: // 공속 증가
				m_player->FastAttack();
				break;
			default:
				break;
			}
			m_player->DecrementLife();
		}
		else {}
	}

	return NULL;
}
