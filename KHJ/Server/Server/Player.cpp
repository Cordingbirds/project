#include "Player.h"

// 이동키값
#define KEY_UP					1
#define KEY_DOWN				2
#define KEY_RIGHT				3
#define KEY_LEFT				4
//케
#define STATE_NORMAL			1
#define STATE_DIZZY				2
#define STATE_BOOSTER			3

CPlayer::CPlayer(){

}
CPlayer::~CPlayer(){}


SC_Player CPlayer::PlayerAccept(int id, SC_Player *packet){
	SC_Player put_PlayerPacket;

	//packet = put_PlayerPacket;

	put_PlayerPacket.ID = id;
	put_PlayerPacket.type = SC_PLAYER;
	put_PlayerPacket.size = sizeof(put_PlayerPacket);
	put_PlayerPacket.rotate_x = players[id].rotateX;

	return put_PlayerPacket;
}

