/*!
* \file RecosterInfo.h
* \date 2016/01/21 4:56
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

#ifndef RecosterInfo_h__
#define RecosterInfo_h__

#include "Component.h"
#include "Enum.h"

class CRecosterInfo : public CComponent
{
public :
	const static WORD MAX_RECOSTER_NUM		= 3;

public:
	WORD			m_wRecoterNum;
	WORD			m_wRecoterGauge;

public:
	static CComponent*		Create();
public :
	virtual void			Update();
private:
	virtual void			Release();

public:
	explicit CRecosterInfo();
	virtual ~CRecosterInfo();
};


#endif // RecosterInfo_h__
