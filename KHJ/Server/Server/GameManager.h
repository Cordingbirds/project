#pragma once

#include "Protocol.h"

using namespace std;

class CGameManager : public SingleTon < CGameManager >{
	

public:
	CGameManager();
	~CGameManager();

	enum state{
		standby		= 0,
		start		= 1,
		playing		= 2,
		end			= 3,
	};
	int state = 0;
	int m_room;
	
	void GameState(int m_room, int state);		//게임 스타트 관리

};