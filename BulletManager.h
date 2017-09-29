#pragma once

//class CEnemyManager;
class CPlayerInfo;

class CBulletManager : public CBaseObject
{
private:
	CBullet* bulletList[50];
	CPlayerInfo* m_player;

public :
	int bulletCount; // ���� �����Ǿ� �ִ� �Ѿ��� ����
public:
	CBulletManager();
	~CBulletManager();

public:
	void Init(); // Initualize
	void Init(CPlayerInfo* player);
	void Render();
	void Frame(int m_bulletType); // Pulse
	void Terminate();

	CBullet* OnObject();
	CImageInfo* CheckCol(bool bulletType);
	void DelBullet();
};