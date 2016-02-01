#pragma once

#include "Protocol.h"

using namespace std;

//template <class T>
class CTimer : public SingleTon <CTimer>, public CGameManager {

public:	
	CTimer();
	~CTimer();

	int m_time;

	void TimeCount();
	void TimeState(int state);

};