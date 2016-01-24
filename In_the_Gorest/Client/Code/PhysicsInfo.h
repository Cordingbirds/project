/*!
* \file PhysicsInfo.h
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

#ifndef PhysicsInfo_h__
#define PhysicsInfo_h__

#include "Component.h"
#include "Enum.h"

class CPhysicsInfo : public CComponent
{
public:
	D3DXVECTOR3		m_vPos;
	D3DXVECTOR3		m_vDir;
	float			m_fRadian[RADIAN_END];

	D3DXMATRIX		m_matWorld;


	float			m_fSpeed;
	float			m_fAccel;
	float			m_fWeight;


public:
	static CComponent*		Create();
public :
	virtual void			Update();
private:
	virtual void			Release();

public:
	explicit CPhysicsInfo();
	virtual ~CPhysicsInfo();
};


#endif // PhysicsInfo_h__
