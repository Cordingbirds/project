#pragma once

#include "Protocol.h"
using namespace std;

class CItem{

public:	
	CItem();
	~CItem();

	bool isExist;									//������ ���� ����

	void ItemSet(float x, float y, float z);
	void ItemAvoid(bool m_exist);

};