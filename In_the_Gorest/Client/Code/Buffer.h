/*!
 * \file Buffer.h
 * \date 2016/01/24 4:18
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

#ifndef Buffer_h__
#define Buffer_h__

#include "Resource.h"


class CDevice;
class CBuffer abstract : public CResource
{
protected:
	ID3D11RasterizerState*		m_pRasterizerState;

protected: // Vectex
	ID3D11Buffer*		m_pVtxBuffer;
	UINT				m_nVtxNum;
	UINT				m_nVtxStride;
	UINT				m_nVtxOffset;

protected: // Index
	ID3D11Buffer*		m_pIdxBuffer;
	UINT				m_nIdxNum;
	UINT				m_nStartIdx;
	UINT				m_nPlusIdx;


public :
	virtual void			Render();


protected:
	virtual void	CreateRasterizerState();
	void			ReleaseBuffer();

protected:
	explicit CBuffer(CDevice*);
public :
	virtual ~CBuffer()		PURE;
};


struct VertexColor
{
	D3DXVECTOR3		vPos;
	D3DXVECTOR4		vColor;
};

struct VertexTexture
{
	D3DXVECTOR3		vPos;
	D3DXVECTOR3		vNormal;
	D3DXVECTOR2		vUV;
};

struct Index16
{
	WORD	_1, _2, _3;

	Index16(WORD _1, WORD _2, WORD _3) : _1(_1), _2(_2), _3(_3) {}
};

struct Index32
{
	DWORD	_1, _2, _3;

	Index32(DWORD _1, DWORD _2, DWORD _3) : _1(_1), _2(_2), _3(_3) {}
};


#endif // Buffer_h__
