#pragma once

#include <Windows.h>
#include "Protocol.h"
using namespace std;

class CItem{

public:	
	CItem();
	~CItem();

	bool isExist;									//아이템 존재 여부

	void SetItem(float x, float y, float z);
	void AvoidItem(bool m_exist);

};