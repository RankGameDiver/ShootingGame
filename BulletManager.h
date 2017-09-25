#pragma once

class CEnemyManager;
class CPlayerInfo;

class CBulletManager : public CBaseObject
{
private:
	CBullet* bulletList[200];

public:
	CBulletManager();
	~CBulletManager();

public:
	void Init(); // Initualize
	void Render();
	void Frame(int m_bulletType); // Pulse
	void Terminate();

	CBullet* OnObject();
	CImageInfo* CheckCol(bool bulletType);
};