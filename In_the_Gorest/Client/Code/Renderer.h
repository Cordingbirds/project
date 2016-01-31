/*!
 * \file Renderer.h
 * \date 2016/01/11 1:44
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

#ifndef Renderer_h__
#define Renderer_h__

#include "Scene.h"

class CDevice;
class CColorShader;
class CRenderer
{
private :
	CDevice*		m_pDevice;
	CScene*			m_pScene;
	CColorShader*	m_pColorShader;

public :
	static CRenderer* Create(CDevice* _pDeviceClass);

public :
	void SetScene(CScene* _pScene)	{ m_pScene = _pScene; }

public :
	HRESULT	Init();
	void	Render();


private:
	explicit CRenderer(CDevice*);
public:
	~CRenderer(void);
};

#endif // Renderer_h__
