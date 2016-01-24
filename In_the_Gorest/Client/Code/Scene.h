/*!
 * \file Scene.h
 * \date 2015/12/08 11:38
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

#ifndef Scene_h__
#define Scene_h__

class CDevice;
class CLayer;
class CScene
{
protected:
	CDevice*				m_pDevice;
	map<WORD, CLayer*>		m_mapLayer;

public:
	virtual HRESULT		Init()			PURE;
	virtual void		Update()		PURE;
	virtual void		Render()		PURE;
	virtual void		Release()		PURE;

public :
	void Update_Layer();
	void Render_Layer();
private :
	void ReleaseLayer();


public:
	CScene(CDevice* _pDevice);
	~CScene();
};

#endif // Scene_h__


