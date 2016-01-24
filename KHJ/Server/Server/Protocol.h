#pragma once

#include <Windows.h>
#include <stdio.h>
#include <iostream>

#include "GameManager.h"
#include "Item.h"
#include "MemoryPool.h"
#include "Player.h"
#include "SingleTon.h"
#include "Timer.h"

#define MAXUSER					1000
#define SERVER_PORT				9000

#define MAX_BUFFER_SIZE			4000
#define MAX_PACKET_SIZE			255

// 이동키값
#define CS_KEY_UP				1
#define CS_KEY_DOWN				2
#define CS_KEY_RIGHT			3
#define CS_KEY_LEFT				4

// 아이템 사용
#define CS_ITEM_RECOVERY		1
#define CS_ITME_BOOSTER			2

// 케릭터 상태
#define SC_STATE_NORMAL			1
#define SC_STATE_DIZZY			2
#define SC_STATE_BOOSTER		3

using namespace std;
#pragma pack (push, 1)

struct CS_packet_key{				// 키 값
	int ID;
	BYTE type;
	BYTE size;
};

struct CS_ItemGet{					// 아이템 획득
	int ID;
	BYTE type;
	BYTE size;
};

struct CS_Use_Recuster{				// 리커스터 사용
	int ID;
	BYTE itemType;
	int Room;						// 방 번호
	BYTE type;
	BYTE size;
};

struct CS_Shoot{					// 총 쏘기
	int ID;
	BYTE type;
	BYTE size;
};

struct SC_packet_Player{			// 플레이어 위치
	float x;
	float y;
	float z;
	float rotate_x;					//좌우
	float rotate_y;					//상하
	int ID;		
	int state;						//케릭터 상태 
	BYTE size;
	BYTE type;
};
 
struct CS_packet_PlayerHP{			// 플레이어 HP
	int HP;
	BYTE type;
	BYTE size;
};

struct SC_packet_Recuster{			// 리커스터 게이지 
	int gage;
	BYTE type;
	BYTE size;
};

struct SC_packet_Item{				// 아이템 위치
	float x;
	float y;
	float z;
	BYTE type;
	BYTE size;
};

struct SC_Timer{
	float time;
	BYTE type;
	BYTE size;
};
struct SC_Room{
	int num;
	int ID[8];
	BYTE type;
	BYTE size;
};

#pragma pack (pop)