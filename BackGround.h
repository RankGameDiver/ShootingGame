#pragma once
#include "BaseObject.h"

class CBackGround : public CBaseObject // PlayerInfo(�÷��̾� ����)�� BaseObject�� IInputHandler�� ��ӹް� �ִ�
{
public:
	CBackGround();
	virtual ~CBackGround();

public:
	bool Initialize(int a); // �ʱ� ����
	bool Initialize(int a,int b);
	void Terminate(); // ����
	bool Pulse(); // �� ������
	void Render(); // ȭ�鿡 �׸�
};