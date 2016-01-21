#include <Windows.h>

#define MAXUSER					1000
#define SERVER_PORT				9000

#define MAX_BUFFER_SIZE			4000
#define MAX_PACKET_SIZE			255

#pragma pack (push, 1)

struct packet_Player{
	BYTE x;
	BYTE y;
	BYTE z;
	WORD ID;
	BYTE HP;				
	BYTE recuster;			//리커스터 게이지
};

struct packet_Item{
	BYTE x;
	BYTE y;
	BYTE z;
	BOOL exist;
};

#pragma pack (pop)