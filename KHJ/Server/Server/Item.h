#pragma once

#include <Windows.h>
#include "Protocol.h"
using namespace std;

class CItem{

public:	
	CItem();
	~CItem();

	bool isExist;									//������ ���� ����

	void SetItem(float x, float y, float z);
	void AvoidItem(bool m_exist);

};