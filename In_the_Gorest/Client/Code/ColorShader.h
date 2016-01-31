/*!
 * \file ColorShader.h
 * \date 2016/01/30 20:59
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

#ifndef ColorShader_h__
#define ColorShader_h__

#include "Shader.h"

class CDevice;
class CColorShader : public CShader
{
public:
	static CComponent*		Create(CDevice*);

public :
	HRESULT			Init();
	virtual void	Update();
	void			Render();
	virtual void	Release();

	 
protected:
	explicit CColorShader(CDevice*);
public:
	virtual ~CColorShader();
};


#endif // ColorShader_h__
