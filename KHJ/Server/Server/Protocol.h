#pragma once
#pragma comment(lib, "ws2_32")
#include <WinSock2.h>
#include <Windows.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <mutex>
#include <thread>

//#include "GameManager.h"
//#include "Item.h"
//#include "MemoryPool.h"
//#include "Player.h"
//#include "SingleTon.h"
//#include "Timer.h"
//#include "Server.h"
//#include "Gun.h"

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
#define SC_PLAYER				1
#define SC_ITEM					2
#define SC_TIMER				3
#define SC_SHOOT				4

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
	float x;
	float y;
	float z;
	float rotateX;
	float rotateY;
	SOCKET sock;
	bool in_use;
	OVERAPPED_EX my_overapped;
	//set<int> view_list;						// ���� �ʿ�� ��� ����
	//mutex	vl_lock;							// ��� ũ��Ƽ�� ���� ���
};


#pragma pack (push, 1)

struct CS_key{						// Ű ��
	BYTE type;						// 1		
	BYTE size;
	int movetype;					// 1234
};
struct CS_Rotate{					// �÷��̾� ȸ��
	BYTE type;						//2
	BYTE size;
	float rotateX;
	float rotateY;
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
	BYTE type;						//1
	BYTE size;						
	float x;
	float y;
	float z;
	float rotate_x;					//�¿�
	float rotate_y;					//����
	int ID;		
	int state;						//�ɸ��� ���� -> ���Ŀ� ����Ʈ �߰� �� ���
};

struct SC_Item{						// ������ ��ġ
	BYTE type;						// 2
	BYTE size;
	float x;
	float y;
	float z;
	bool isExist;
};

struct SC_Timer{
	BYTE type;						// 3
	BYTE size;
	float time;
};

struct SC_Shoot{							
	BYTE type;						// 4
	BYTE size;
	int ID;
};

struct SC_Room{
	BYTE type;
	BYTE size;
	int num;
	int ID[8];
};

#pragma pack (pop)