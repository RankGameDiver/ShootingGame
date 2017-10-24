#pragma once

//class CEnemyManager;
class CPlayerInfo;

class CItemManager : public CBaseObject
{
private:
	CItem* item;
	CPlayerInfo* m_player;

public:
	CItemManager();
	~CItemManager();

public:
	void Init(); // Initualize
	void Init(CPlayerInfo* player);
	void Render();
	void Frame(int itemType); // Pulse
	void Terminate();

	CItem* OnObject(int type);
	CItem* SetAct(bool bIsActive);
	bool GetAct();

	CImageInfo* CheckCol(bool itemType);
};

#define g_pItemManager	CItemManager::GetSingleton()