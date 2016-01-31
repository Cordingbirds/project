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

class CDevice;
class CPhysicsInfo : public CComponent
{
public :
	CDevice*		m_pDevice;
	ID3D11Buffer*	m_pWorldBuffer;

public:
	D3DXVECTOR3		m_vPos;
	D3DXVECTOR3		m_vDir;
	float			m_fRadian[RADIAN_END];

	D3DXMATRIX		m_matWorld;

	float			m_fSpeed;
	float			m_fAccel;
	float			m_fWeight;


public:
	static CComponent*		Create(CDevice*);
public :
	void					Init();
	virtual void			Update();
private:
	virtual void			Release();


private:
	void Init_WorldBuffer();


public:
	explicit CPhysicsInfo(CDevice*);
	virtual ~CPhysicsInfo();
};


#endif // PhysicsInfo_h__
