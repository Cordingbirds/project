#pragma once

#include "Protocol.h"

class CPlayer{

public:	
	
	CPlayer();
	~CPlayer();

	enum state{
		normal	= 1,
		dizzy	= 2,
		booster = 3,
	};
	float x;
	float y;
	float z;

	int HP;
	int state;

	int m_room;									// 방 번호
	int m_ID;									// 방 입장 순서

	void InitPlayer (int m_ID, int m_room);		// 게임 시작 시 플레이어
	void PlayerPos (float x, float y, float z);		// 플레이어 위치
	int ChangePlayerState (int state);		// 상태

	float RotateX (float rotate);			// 좌우회전
	float RotateY (float rotate);			// 상하회전

	void UseItem ();							// 아이템 사용
	void UetItem ();							// 아이템 획득

	void ShootGun ();						// 총 쏘기
	int PlayerHP (int HP);					// HP관리
};