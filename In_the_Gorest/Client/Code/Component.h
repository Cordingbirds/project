/*!
 * \file Component.h
 * \date 2016/01/11 3:43
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

#ifndef Component_h__
#define Component_h__

class CComponent
{
protected:
	WORD*			m_pRefCnt;

public :
	virtual void			Update()	PURE;
	virtual CComponent*		Clone()		PURE;

protected:
	void Release();

public :
	explicit CComponent();
	virtual ~CComponent();
};

#endif // Component_h__
