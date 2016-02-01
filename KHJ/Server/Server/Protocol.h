#pragma once

#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <mutex>
#include <thread>
#include <WinSock2.h>

#include "GameManager.h"
#include "Item.h"
#include "MemoryPool.h"
#include "Player.h"
#include "SingleTon.h"
#include "Timer.h"
#include "Server.h"

#define MAXUSER					1000
#define SERVER_PORT				9000

#define MAX_BUFFER_SIZE			4000
#define MAX_PACKET_SIZE			255

//C->S
#define CS_KEY					1
#define CS_ROTATE				2
#define CS_ITEMGET				3
#define CS_SHOOT				4

//S->C
#define CS_PLAYER				1
#define CS_ITEM					2
#define CS_TIMER				3
#define CS_SHOOT				4

using namespace std;

struct OVERAPPED_EX {
	WSAOVERLAPPED overapped;
	int operation_type;
	WSABUF wsabuf;
	char IOCPbuf[MAX_BUFFER_SIZE];
	char PacketBuf[MAX_PACKET_SIZE];
	unsigned int prev_received;
	unsigned int curr_packet_size;
};
struct PLAYER {
	int x;
	int y;
	int y;
	float rotateX;
	float rotateY;
	SOCKET sock;
	bool in_use;
	OVERAPPED_EX my_overapped;
	set<int> view_list;
	mutex	vl_lock;
};

#pragma pack (push, 1)

struct CS_key{						// Ű ��
	float speed;
	BYTE movetype;					// 1234
	BYTE type;						// 1		
	BYTE size;
};
struct CS_Rotate{					// �÷��̾� ȸ��
	float rotateX;
	float rotateY;
	BYTE type;						//2
	BYTE size;
};

struct CS_ItemGet{					// ������ ȹ��
	BYTE type;						//3
	BYTE size;
};

struct CS_ShootKey{					// �� ��� Ű �ޱ�
	BYTE type;						// 4
	BYTE size;
};

struct SC_Player{					// �÷��̾� ��ġ
	float x;
	float y;
	float z;
	float rotate_x;					//�¿�
	float rotate_y;					//����
	int ID;		
	int state;						//�ɸ��� ���� -> ���Ŀ� ����Ʈ �߰� �� ���
	BYTE size;
	BYTE type;						//1
};

struct SC_Item{						// ������ ��ġ
	float x;
	float y;
	float z;
	bool isExist;
	BYTE type;						// 2
	BYTE size;
};

struct SC_Timer{
	float time;
	BYTE type;						// 3
	BYTE size;
};

struct SC_Shoot{
	int ID;							
	BYTE type;						// 4
	BYTE size;
};

struct SC_Room{
	int num;
	int ID[8];
	BYTE type;
	BYTE size;
};

#pragma pack (pop)