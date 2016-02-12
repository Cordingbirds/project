#include <WinSock2.h>
#include <windows.h>  
#include <stdio.h>
#include <conio.h>		

#include "..\..\Server\server\Protocol.h"
#pragma comment (lib, "ws2_32.lib")

#define WM_SOCKET		WM_USER + 1

SOCKET sock;
WSABUF send_wsabuf;
char  send_buffer[MAX_BUFFER_SIZE];
WSABUF recv_wsabuf;
char recv_buffer[MAX_BUFFER_SIZE];
char packet_buffer[MAX_BUFFER_SIZE];
DWORD in_packet_size = 0;
int saved_packet_size = 0;
int myid;
HWND handle;

// 소켓 함수 오류 출력 후 종료
void err_quit(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	LocalFree(lpMsgBuf);
	exit(1);
}

// 소켓 함수 오류 출력
void err_display(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	LocalFree(lpMsgBuf);
}

// 사용자 정의 데이터 수신 함수
int recvn(SOCKET s, char *buf, int len, int flags)
{
	int received;
	char *ptr = buf;
	int left = len;

	while (left > 0){
		received = recv(s, ptr, left, flags);
		if (received == SOCKET_ERROR)
			return SOCKET_ERROR;
		else if (received == 0)
			break;
		left -= received;
		ptr += received;
	}

	return (len - left);
}

void ProcessPakcet(char *ptr){
	static bool first_time = true;
	switch (ptr[0]){
	case SC_PLAYER:
	{
		break;
	}
	case SC_ITEM:
	{

		break;
	}
	case SC_TIMER:
	{

		break;
	}
	case SC_SHOOT:
	{

		break;
	}

	}
}
void ReadPacket(SOCKET sock){

}
DWORD server(){
	int retval;

	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) 
		err_quit("socket()");

	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serveraddr.sin_port = htons(SERVER_PORT);
	retval = connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) 
		err_quit("connect()");

	//WSAAsyncSelect(sock, handle, WM_SOCKET, FD_CLOSE | FD_READ);


}

void main(){
	int key;
	int x = 0, y = 0;

	while (1){
		key = getch();
		if (key == 72)			//위
			y++;
		if (key == 80)			//아래
			y--;
		if (key == 75)			//왼
			x--;
		if (key == 77)			//오른
			x++;
	}
}