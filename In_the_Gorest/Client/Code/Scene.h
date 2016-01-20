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

class CLayer;
class CScene
{
protected:
	ID3D11Device*			m_pDevice;
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
	CScene(ID3D11Device* _pDevice);
	~CScene();
};

#endif // Scene_h__


