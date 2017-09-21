// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>
#include <mmsystem.h>

// DirectX9 ��� ����
#include <d3d9.h>
#include <d3dx9.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#define MAX_LOADSTRING			(128)
#define MAX_IMAGE				(128)
#define MAX_TEXTURE				(128)
#define MAX_PLAYER_LIFE			(3)
#define MAX_ENEMY_LIFE			(3)
#define MAX_PLAYER_FRAME		(8)
#define MAX_PLAYER_SPEED		(400.0f)
#define SCREEN_WIDTH			(1024)
#define SCREEN_HEIGHT			(800)

#include "resource.h"
#include "Singleton.h"
#include "Vector2d.h"
#include "IScene.h"
#include "ImageInfo.h"
#include "BaseWindow.h"
#include "BaseRender.h"
#include "TimeManager.h"
#include "FrameSkip.h"
#include "Gdi.h" 
#include "GraphicManager.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "InputManager.h"
#include "ImageManager.h"
#include "BackGround.h"
#include "PlayerInfo.h"
#include "Enemy.h"
#include "Bullet.h"
#include "MainProc.h"
#include "Intro.h"
#include "Menu.h"
#include "InGame.h"
#include "FirstStage.h"
#include "System.h"


