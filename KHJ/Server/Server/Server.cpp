#include "Protocol.h"

using namespace std;

PLAYER players[8];					//접속자 수

CServer::CServer(){}

CServer::~CServer(){}

void CServer::PlayerInit(int id){
	ZeroMemory(&players[id].my_overapped, sizeof(OVERAPPED_EX));
	players[id].in_use = false;
	players[id].my_overapped.operation_type = OP_RECV;
	players[id].my_overapped.wsabuf.buf = players[id].my_overapped.IOCPbuf;
	players[id].my_overapped.wsabuf.len = sizeof(players[id].my_overapped.IOCPbuf);
	players[id].view_list.clear();
}

void CServer::SendPacket(int id, void *packet)
{
	int packet_size = reinterpret_cast<unsigned char *>(packet)[0];

	OVERAPPED_EX *send_over = new OVERAPPED_EX;
	ZeroMemory(send_over, sizeof(OVERAPPED_EX));
	send_over->operation_type = OP_SEND;
	send_over->wsabuf.buf = send_over->IOCPbuf;
	send_over->wsabuf.len = packet_size;
	unsigned long io_size;

	memcpy(send_over->IOCPbuf, packet, packet_size);

	WSASend(players[id].sock, &send_over->wsabuf, 1,
		&io_size, NULL, &send_over->overapped, NULL);
}
