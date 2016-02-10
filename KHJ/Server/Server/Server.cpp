//#include "Protocol.h"
#include "Server.h"

CRITICAL_SECTION cs;					//크리티컬 섹션
//using namespace std;

CPlayer m_player;

CServer::CServer(){}

CServer::~CServer(){}

void CServer::PlayerInit(int id){
	ZeroMemory(&m_player.players[id].my_overapped, sizeof(OVERAPPED_EX));
	m_player.players[id].in_use = false;
	m_player.players[id].my_overapped.operation_type = OP_RECV;
	m_player.players[id].my_overapped.wsabuf.buf = m_player.players[id].my_overapped.IOCPbuf;
	m_player.players[id].my_overapped.wsabuf.len = sizeof(m_player.players[id].my_overapped.IOCPbuf);
	//m_player.players[id].view_list.clear();
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

	WSASend(m_player.players[id].sock, &send_over->wsabuf, 1,
		&io_size, NULL, &send_over->overapped, NULL);
}

void CServer::ProcessPacket(char* packet, int id){

	switch (packet[0])
	{
	case CS_KEY:
		break;
	case CS_ROTATE:
		break;

	}

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
		int id;
		for (int i = 0; i < MAXUSER; ++i){
			if (m_player.players[i].in_use == false){
				PlayerInit(i);
				id = i;
			}
		}
		m_player.players[id].sock = client_socket;
		
		CreateIoCompletionPort(reinterpret_cast<HANDLE>(client_socket),
			hIOCP, id, 0);
		unsigned long recv_flag = 0;

		ret = WSARecv(client_socket, &m_player.players[id].my_overapped.wsabuf, 1, NULL,
			&recv_flag, &m_player.players[id].my_overapped.overapped, NULL);

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
		SC_Player *m_playerpacket;
		m_player.PlayerAccept(id, m_playerpacket);
		SendPacket(id, &m_playerpacket);

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
		
		// 에러로 인한 접속 종료
		if (0 == io_size){
			closesocket(m_player.players[key].sock);
			m_player.players[key].in_use = false;
		}

		//recv
		if (OP_RECV == over_ex->operation_type){
			int rest_size = io_size;
			char* buf = over_ex->IOCPbuf;
			int packet_size = over_ex->curr_packet_size;
			while (0 < rest_size){
				if (0 == packet_size)
					packet_size = buf[0];
				int remain = packet_size - over_ex->prev_received;

				//패킷을 만들기에 공간이 부족한 경우
				if (remain > rest_size){
					memcpy(over_ex->PacketBuf + over_ex->prev_received,
						buf, rest_size);
					over_ex->prev_received += rest_size;
				}
				// 패킷 만들기에 충분
				else{
					memcpy(over_ex->PacketBuf + over_ex->prev_received,
						buf, remain);
					// 프로세스패킷 함수 ( 클라에서 받아온 정보 패킷 처리)

					rest_size -= remain;
					packet_size = 0;
					over_ex->prev_received = 0;
				}
			}
			over_ex->curr_packet_size = packet_size;
			unsigned long recv_flag = 0;
			WSARecv(m_player.players[key].sock, &over_ex->wsabuf, 1, NULL,
				&recv_flag, &over_ex->overapped, NULL);
		}
		//SEND
		else if (OP_SEND == over_ex->operation_type)
			delete over_ex;
	}
}

void main(){
	CServer server;
	vector <thread *> worker_threads;
	server.NetworkInit();

	for (int i = 0; i < MAXUSER; ++i)
		server.PlayerInit(i);

	hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 0);

	while (true){
		Sleep(1000);
	}
}