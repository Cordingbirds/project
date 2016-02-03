/*!
 * \file Camera.h
 * \date 2016/01/30 18:36
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

#ifndef Camera_h__
#define Camera_h__

#include "Obj.h"


class CCamera abstract : public CObj
{
public :
	D3DXMATRIX			m_matView;
	D3DXVECTOR3			m_vEye, m_vAt;
	static const D3DXVECTOR3	m_vUp;

	D3DXMATRIX			m_matProj;
	float				m_fFovy, m_fAspect, m_fNear, m_fFar;

	D3D11_VIEWPORT		m_tViewport;
	
	ID3D11Buffer*		m_pViewBuffer;
	ID3D11Buffer*		m_pProjBuffer;
	

private :
	void	Init_Viewport();
	void	Init_ViewBuffer();
	void	Init_ProjBuffer();

protected:
	void	Invalidate_View();
	void	Invalidate_Proj();

protected:
	explicit CCamera(CDevice* _pDevice);
public :
	virtual ~CCamera()		PURE;
};

struct Buffer_View
{
	D3DXMATRIX			m_matView;
};

struct Buffer_Proj
{
	D3DXMATRIX			m_matProj;
};

#endif // Camera_h__
