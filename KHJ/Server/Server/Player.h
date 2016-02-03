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

	int m_room;									// �� ��ȣ
	int m_ID;									// �� ���� ����

	CServer server;

	int InitPlayer ();					// ���� ���� �� �÷��̾�
	void PlayerPos (float x, float y, float z, int ID);		// �÷��̾� ��ġ
	int ChangePlayerState (int state);						// ����

	float RotateX (float rotate);			// �¿�ȸ��
	float RotateY (float rotate);			// ����ȸ��

	void UseItem ();						// ������ ���
	void UetItem ();						// ������ ȹ��

	void Shoot (int ID);					// �� ���
	int PlayerHP (int HP);					// HP����
};