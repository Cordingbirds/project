#include "Protocol.h"

// �̵�Ű��
#define KEY_UP					1
#define KEY_DOWN				2
#define KEY_RIGHT				3
#define KEY_LEFT				4
//��
#define STATE_NORMAL			1
#define STATE_DIZZY				2
#define STATE_BOOSTER			3


CPlayer::CPlayer(){

}
CPlayer::~CPlayer(){}

int CPlayer::InitPlayer(){
	for (int i = 0; i < MAXUSER; ++i){
		if (players[i].in_use == false){
			server.PlayerInit(i);
			return i;
		}
	}

	

}