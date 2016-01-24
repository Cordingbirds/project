/*!
 * \file CubeColor.h
 * \date 2016/01/24 3:23
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

#ifndef CubeColor_h__
#define CubeColor_h__

#include "Buffer.h"

class CCubeColor : public CBuffer
{
private :


public :
	static CComponent*		Create(CDevice*);
	virtual CComponent*		Clone();

public:
	virtual HRESULT			Init();
	virtual void			Update();
private:
	virtual void			Release();


private :
	void		Init_Vtx();
	void		Init_Idx();

protected:
	explicit CCubeColor(CDevice*);
public:
	virtual ~CCubeColor();
};

#endif // CubeColor_h__
