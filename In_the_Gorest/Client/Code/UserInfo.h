/*!
 * \file UserInfo.h
 * \date 2016/01/21 4:56
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

#pragma once

#ifndef UserInfo_h__
#define UserInfo_h__

#include "Component.h"

class CUserInfo : public CComponent
{
public :
	const wstring	m_wstrIP;
	const wstring	m_wstrID;

	DWORD			m_dwRoomNum;
	bool			m_bReady;

public:
	static CComponent*		Create();
public :
	virtual void			Update();
private:
	virtual void			Release();

public:
	explicit CUserInfo();
	virtual ~CUserInfo();
};


#endif // UserInfo_h__
