/*!
 * \file Resource.h
 * \date 2016/01/11 4:01
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

#ifndef Resource_h__
#define Resource_h__

#include "Component.h"

class CResource : public CComponent
{
private :
	ID3D11Device*			m_pDevice;

public:
	virtual void			Update()	PURE;
	virtual CComponent*		Clone()		PURE;


protected:
	CResource(ID3D11Device*);
public :
	virtual ~CResource();

};

#endif // Resource_h__
