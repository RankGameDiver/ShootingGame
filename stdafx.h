// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>
#include <mmsystem.h>

// DirectX9 헤더 파일
#include <d3d9.h>
#include <d3dx9.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#define MAX_LOADSTRING			(128)
#define MAX_IMAGE				(128)
#define MAX_TEXTURE				(128)
#define MAX_PLAYER_LIFE			(5)
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
#include "TimeManager.h"
#include "FrameSkip.h"
#include "BaseRender.h"
#include "BaseObject.h"
#include "Gdi.h" 
#include "GraphicManager.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "InputManager.h"
#include "ImageManager.h"
#include "MainProc.h"

#include "Item.h"
#include "ItemManager.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "PlayerInfo.h"
#include "Enemy.h"
#include "EnemyManager.h"

#include "BackGround.h"
#include "InGame.h"
#include "Intro.h"
#include "Menu.h"
#include "FirstStage.h"
#include "SecondStage.h"
#include "ThirdStage.h"
#include "System.h"


