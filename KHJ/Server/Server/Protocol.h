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

// �̵�Ű��
#define CS_KEY_UP				1
#define CS_KEY_DOWN				2
#define CS_KEY_RIGHT			3
#define CS_KEY_LEFT				4

// ������ ���
#define CS_ITEM_RECOVERY		1
#define CS_ITME_BOOSTER			2

// �ɸ��� ����
#define SC_STATE_NORMAL			1
#define SC_STATE_DIZZY			2
#define SC_STATE_BOOSTER		3

using namespace std;
#pragma pack (push, 1)

struct CS_packet_key{				// Ű ��
	int ID;
	BYTE type;
	BYTE size;
};

struct CS_ItemGet{					// ������ ȹ��
	int ID;
	BYTE type;
	BYTE size;
};

struct CS_Use_Recuster{				// ��Ŀ���� ���
	int ID;
	BYTE itemType;
	int Room;						// �� ��ȣ
	BYTE type;
	BYTE size;
};

struct CS_Shoot{					// �� ���
	int ID;
	BYTE type;
	BYTE size;
};

struct SC_packet_Player{			// �÷��̾� ��ġ
	float x;
	float y;
	float z;
	float rotate_x;					//�¿�
	float rotate_y;					//����
	int ID;		
	int state;						//�ɸ��� ���� 
	BYTE size;
	BYTE type;
};
 
struct CS_packet_PlayerHP{			// �÷��̾� HP
	int HP;
	BYTE type;
	BYTE size;
};

struct SC_packet_Recuster{			// ��Ŀ���� ������ 
	int gage;
	BYTE type;
	BYTE size;
};

struct SC_packet_Item{				// ������ ��ġ
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