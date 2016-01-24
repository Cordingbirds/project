/*!
* \file KeyMgrMgr.h
* \date 2016/01/25 3:17
*
* \author �����
* Contact: bluevill04@gmail.com
*
* \brief
*
* TODO: long description
*
* \note
*/

/*
[����]

public :
bool CheckKeyBoardDown(BYTE _byKeyFlag);		Ű���尡 ó�� ������ �� true ��ȯ
bool CheckKeyBoardPress(BYTE _byKeyFlag);		Ű���尡 �������� ��� true ��ȯ
bool CheckKeyBoardPressed(BYTE _byKeyFlag);		Ű���尡 ������ ������ �� true ��ȯ

bool CheckMouseDown(MouseType _eKeyFlag);		���콺�� ó�� ������ �� true ��ȯ
bool CheckMousePress(MouseType _eKeyFlag);		���콺�� �������� ��� true ��ȯ
bool CheckMousePressed(MouseType _eKeyFlag);	���콺�� ������ ������ �� true ��ȯ	

if (m_pKeyMgr->CheckKeyBordDown(DIK_S))
{
	// S Ű�� ó�� ������ �� ó��
}

if (m_pKeyMgr->CheckMousePressed(CKeyMgr::MOUSE_TYPE_L))
{
	// ���콺 L ��ư�� ��� ������ ���� �� ó��
}

*/

#pragma once

#ifndef KeyMgrMgr_h__
#define KeyMgrMgr_h__

#include "Define.h"
#include "Value.h"

class CKeyMgr;
class CKeyMgr
{
	DECLARE_SINGLETON(CKeyMgr)

public :
	enum MouseType		{ MOUSE_TYPE_L, MOUSE_TYPE_R, MOUSE_TYPE_MID };
	enum MouseMove		{ MOUSE_MOVE_X, MOUSE_MOVE_Y, MOUSE_MOVE_Z };
	enum MouseWheel		{ MOUSE_WHEEL_NONE, MOUSE_WHEEL_UP, MOUSE_WHEEL_DOWN };

private :
	LPDIRECTINPUT8			m_pInput;
	LPDIRECTINPUTDEVICE8	m_pKeyBoardDevice;
	LPDIRECTINPUTDEVICE8	m_pMouseDevice;
		
private :
	BYTE			m_byKeyState[MAX_KEY];
	bool			m_bKeyDown[MAX_KEY];
	bool			m_bKeyPressd[MAX_KEY];

	DIMOUSESTATE	m_eMouseState;
	bool			m_bMouseDown;
	bool			m_bMousePressed;


public :
	HRESULT Init(HINSTANCE _hInst, HWND _hWnd);
	HRESULT InitKeyBoard(HWND _hWnd);
	HRESULT InitMouse(HWND _hWnd);

public :
	void UpdateInputState();

public:
	BYTE GetDIKeyState(BYTE _byKeyFlag)					{ return m_byKeyState[_byKeyFlag]; }
	BYTE GetDIMouseState(MouseType _eKeyFlag)			{ return m_eMouseState.rgbButtons[_eKeyFlag]; }
	long GetDIMouseMove(MouseMove _eKeyFlag)			{ return *(((long*)&m_eMouseState) + _eKeyFlag); }

public :
	bool CheckKeyBoardDown(BYTE _byKeyFlag);
	bool CheckKeyBoardPress(BYTE _byKeyFlag);
	bool CheckKeyBoardPressed(BYTE _byKeyFlag);
	
	bool CheckMouseDown(MouseType _eKeyFlag);
	bool CheckMousePress(MouseType _eKeyFlag);
	bool CheckMousePressed(MouseType _eKeyFlag);

public:
	void Release();

private:
	CKeyMgr();
	~CKeyMgr();
};


#endif // KeyMgrMgr_h__
