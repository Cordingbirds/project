/*!
* \file KeyMgrMgr.h
* \date 2016/01/25 3:17
*
* \author 김명지
* Contact: bluevill04@gmail.com
*
* \brief
*
* TODO: long description
*
* \note
*/

/*
[사용법]

public :
bool CheckKeyBoardDown(BYTE _byKeyFlag);		키보드가 처음 눌렸을 때 true 반환
bool CheckKeyBoardPress(BYTE _byKeyFlag);		키보드가 눌려있을 경우 true 반환
bool CheckKeyBoardPressed(BYTE _byKeyFlag);		키보드가 눌리고 떼졌을 때 true 반환

bool CheckMouseDown(MouseType _eKeyFlag);		마우스가 처음 눌렸을 때 true 반환
bool CheckMousePress(MouseType _eKeyFlag);		마우스가 눌려있을 경우 true 반환
bool CheckMousePressed(MouseType _eKeyFlag);	마우스가 눌리고 떼졌을 때 true 반환	

if (m_pKeyMgr->CheckKeyboardDown(DIK_S))
{
	// S 키가 처음 눌렸을 때 처리
}

if (m_pKeyMgr->CheckMousePressed(CKeyMgr::MOUSE_TYPE_L))
{
	// 마우스 L 버튼이 계속 눌리고 있을 때 처리
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
