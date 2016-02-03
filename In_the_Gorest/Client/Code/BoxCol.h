/*!
 * \file BoxCol.h
 * \date 2016/01/24 9:37
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

#ifndef BoxCol_h__
#define BoxCol_h__

#include "Collision.h"

class CBuffer;
class CBoxCol : public CCollision
{
private:
	CBuffer*		m_pBuffer;
	ID3D11Buffer*	m_pWorldBuffer;

public:
	D3DXVECTOR3*		m_pOwnerPos;
	D3DXVECTOR3			m_vPlusPos;
	D3DXVECTOR3			m_vScale;


public:
	static CComponent*		Create(CDevice*);
public:
	HRESULT					Init();
	virtual void			Update();
	void					Render();
private:
	virtual void			Release();


public:
	const D3DXVECTOR3	GetPos()		{ return (*m_pOwnerPos) + m_vPlusPos;  }
	const D3DXVECTOR3	GetScale()		{ return m_vScale;  }


private :
	CBoxCol(CDevice*);
public :
	~CBoxCol();
};

#endif // BoxCol_h__
