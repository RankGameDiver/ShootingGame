#pragma once
class CBulletManager
{
private:
	CBullet* bulletList[200];

public:
	CBulletManager();
	~CBulletManager();

public:
	void Initialize();
	void Render();
	void Pulse();
	void Terminate();

	CBullet* OnObject();
};