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

	void InitPlayer (int m_ID, int m_room);		// ���� ���� �� �÷��̾�
	void PlayerPos (float x, float y, float z);		// �÷��̾� ��ġ
	int ChangePlayerState (int state);		// ����

	float RotateX (float rotate);			// �¿�ȸ��
	float RotateY (float rotate);			// ����ȸ��

	void UseItem ();							// ������ ���
	void UetItem ();							// ������ ȹ��

	void ShootGun ();						// �� ���
	int PlayerHP (int HP);					// HP����
};