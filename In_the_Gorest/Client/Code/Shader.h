/*!
 * \file Shader.h
 * \date 2016/01/30 18:23
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

#ifndef Shader_h__
#define Shader_h__

#include "Component.h"

class CDevice;
class CShader abstract : public CComponent
{
protected:
	CDevice*		m_pDevice;

	ID3D11VertexShader*		m_pVertexShader;
	ID3D11InputLayout*		m_pVertexLayout;

	ID3D11PixelShader*		m_pPixelShader;
	//ID3D11GeometryShader*	m_pGeometryShader;


protected:
	explicit CShader(CDevice*);
public:
	virtual ~CShader()			PURE;
};

#endif // Shader_h__
