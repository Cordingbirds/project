#include "Protocol.h"

using namespace std;

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

void CServer::Accept_thread(){
	struct sockaddr_in listen_addr;
	struct sockaddr_in client_addr;

	SOCKET listen_socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL,
		0, WSA_FLAG_OVERLAPPED );

	ZeroMemory(&listen_addr, sizeof(listen_addr));
	// listen
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	listen_addr.sin_port = htons(SERVER_PORT);
	ZeroMemory(&listen_addr.sin_zero, 8);

	int ret = ::bind(listen_socket, reinterpret_cast<sockaddr*>(&listen_addr),
		sizeof(listen_addr));
	if (SOCKET_ERROR == ret){
		error_display("BIND", WSAGetLastError());
		exit(-1);
	}
	ret = listen(listen_socket, 8);
	if (SOCKET_ERROR == ret) {
		error_display("LISTEN", WSAGetLastError());
		exit(-1);
	}
	while (true){
		int addr_size = sizeof(client_addr);
		SOCKET client_socket = WSAAccept(listen_socket, reinterpret_cast<sockaddr*>(&client_addr),
			&addr_size, NULL, NULL);
		if (INVALID_SOCKET == client_socket){
			error_display("Accept", WSAGetLastError());
			exit(-1);
		}

		// 플레이어 접속 / 위치 / 상태
		int id = m_player.InitPlayer();
		players[id].sock = client_socket;
		
		CreateIoCompletionPort(reinterpret_cast<HANDLE>(client_socket),
			hIOCP, id, 0);
		unsigned long recv_flag = 0;

		ret = WSARecv(client_socket, &players[id].my_overapped.wsabuf, 1, NULL,
			&recv_flag, &players[id].my_overapped.overapped, NULL);

		if (SOCKET_ERROR == ret){
			int err_code = WSAGetLastError();
			if (WSA_IO_PENDING != err_code){
				error_display("Accept(WSARecv):", err_code);
				exit(-1);
			}
		}
		// 플레이어 패킷 담기
		// 서버에서 클라로 보내줄 플레이어 패킷
		// SC_Player
		// CPlayer에서 해주자
	}
}

void CServer::worker_thread(){

	while (true)
	{
		unsigned long io_size;
		unsigned long key;
		OVERAPPED_EX *over_ex;
		GetQueuedCompletionStatus(hIOCP, &io_size, &key, 
			reinterpret_cast<LPOVERLAPPED*> (&over_ex), INFINITE);

		if (0 == io_size){
			closesocket(players[key].sock);

		}
	}
}

