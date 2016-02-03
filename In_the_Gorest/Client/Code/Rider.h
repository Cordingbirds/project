/*!
* \file Player.h
* \date 2016/01/24 11:29
*
* \author ±è¸íÁö
* Contact: bluevill04@gmail.com
*
* \brief
*
* TODO: long description
*
* \note
*/
#pragma once

#ifndef Rider_h__
#define Rider_h__

#include "Unit.h"

#include "UserInfo.h"
#include "PlayingInfo.h"
#include "RecosterInfo.h"


class CRider abstract : public CUnit
{
protected :
	CUserInfo*				m_pUserInfo;
	CPlayingInfo*			m_pPlayingInfo;
	CRecosterInfo*			m_pRecosterInfo;

private:
	void	AddComponent();

protected:
	explicit CRider(CDevice* _pDevice);
public:
	virtual ~CRider()	PURE;
};

#endif // Rider_h__
