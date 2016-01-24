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
class CBuffer : public CResource
{
protected:
	ID3D11RasterizerState*		m_pRasterizerState;

protected: // Vectex
	ID3D11Buffer*		m_pVtxBuffer;
	UINT				m_nVtxNum;
	UINT				m_nVtxByte;
	UINT				m_nVtxOffset;

protected: // Index
	ID3D11Buffer*		m_pIdxBuffer;
	UINT				m_nIdxNum;
	UINT				m_nStartIdx;
	UINT				m_nPlusIdx;


public:
	virtual CComponent*		Clone()		PURE;
	virtual void			Update()	PURE;
	virtual void			Render();
private:
	virtual void			Release()	PURE;

protected:
	virtual void	CreateRasterizerState();
	void			ReleaseBuffer();

protected:
	explicit CBuffer(CDevice*);
public :
	virtual ~CBuffer();
};


struct VertexColor
{
	D3DXVECTOR3		vPos;
	D3DXVECTOR3		vNormal;
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
};

struct Index32
{
	DWORD	_1, _2, _3;
};


#endif // Buffer_h__
