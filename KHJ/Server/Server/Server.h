#include "Protocol.h"
#include "Player.h"
//#include <WinSock2.h>

const int NUM_THREADS = 6;
const int STARTING_X = 4;
const int STARTING_Y = 4;

HANDLE hIOCP;

const int OP_SEND = 0;
const int OP_RECV = 1;
const int OP_MOVE = 2;


const int EVENT_MOVE = 0;
const int EVENT_CHASE = 1;
const int EVENT_ATTACK = 2;
const int EVENT_HEAL = 3;



class CServer{
public:
	CServer();
	~CServer();

	void error_display(char *msg, int err_no)
	{
		WCHAR *lpMsgBuf;
		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM,
			NULL, err_no,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&lpMsgBuf, 0, NULL);
		printf("%s :", msg);
		wprintf(L"����%s\n", lpMsgBuf);
		LocalFree(lpMsgBuf);
	}
	void NetworkInit()
	{
		WSADATA wsadata;
		WSAStartup(MAKEWORD(2, 2), &wsadata);
	}

	void PlayerInit(int id);
	void SendPacket(int id, void *packet);
	void ProcessPacket(char *packet, int id);
	void Accept_thread();
	void worker_thread();

	void servermain();
};