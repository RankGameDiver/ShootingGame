#pragma once
#include "BaseObject.h"

class CBackGround : public CBaseObject // PlayerInfo(�÷��̾� ����)�� BaseObject�� IInputHandler�� ��ӹް� �ִ�
{
public:
	CBackGround();
	virtual ~CBackGround();

public:
	bool Initialize(); // �ʱ� ����
	void Terminate(); // ����
	bool Pulse(); // �� ������
	void Render(); // ȭ�鿡 �׸�
};