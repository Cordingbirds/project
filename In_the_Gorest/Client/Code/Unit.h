/*!
 * \file Unit.h
 * \date 2016/01/24 11:12
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

#pragma once

#ifndef Unit_h__
#define Unit_h__

/* 3D 좌표를 갖는 Obj는 Unit로 간주한다. */

#include "Obj.h"

#include "PhysicsInfo.h"
#include "BoxCol.h"


class CUnit abstract : public CObj
{
//protected:
	ID3D11Buffer*		m_pWorldMarixBuffer;

protected :
	CPhysicsInfo*		m_pPhysicsInfo;
	CBoxCol*			m_pBoxCol;

private :
	void	CreateWorldMarixBuffer(CDevice* _pDevice);
	void	AddComponent();

protected:
	explicit CUnit(CDevice* _pDevice);
public :
	virtual ~CUnit()	PURE;
};

#endif // Unit_h__
