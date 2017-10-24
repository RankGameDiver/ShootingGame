#pragma once
#include "BaseObject.h"

class CBackGround : public CBaseObject // PlayerInfo(플레이어 정보)는 BaseObject와 IInputHandler를 상속받고 있다
{
public:
	CBackGround();
	virtual ~CBackGround();

public:
	bool Initialize(int a); // 초기 설정
	bool Initialize(int a,int b);
	void Terminate(); // 제거
	bool Pulse(); // 매 프레임
	void Render(); // 화면에 그림
};