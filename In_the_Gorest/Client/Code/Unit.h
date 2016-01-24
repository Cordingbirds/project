/*!
 * \file Unit.h
 * \date 2016/01/24 11:12
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

#ifndef Unit_h__
#define Unit_h__

/* 3D ��ǥ�� ���� Obj�� Unit�� �����Ѵ�. */

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
