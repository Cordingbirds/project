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

#ifndef Player_h__
#define Player_h__

#include "Rider.h"


class CPlayer : public CRider
{
private :

public :
	static CObj*	Create(CDevice*);

public:
	virtual HRESULT	Init();
	virtual int		Update();
	virtual void	Render();
	virtual void	Release();

private :
	explicit CPlayer(CDevice*);
public :
	virtual ~CPlayer();
};

#endif // Player_h__
