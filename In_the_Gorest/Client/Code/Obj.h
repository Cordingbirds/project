/*!
 * \file Obj.h
 * \date 2016/01/11 4:10
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

#ifndef Obj_h__
#define Obj_h__

#include "Include.h"


class CComponent;
class CObj
{
protected:
	ID3D11Device*			m_pDevice;
	ObjState				m_eObjState;

	map<wstring, CComponent*>	m_mapComponent;


public :
	const CComponent*	GetComponent(const wstring&	_wstrComponentKey);

	ObjState	GetObjState()						{ return m_eObjState; }
	void		SetObjState(ObjState _eObjState)	{ m_eObjState = _eObjState; }


public :
	void	Update_Component();
private :
	void	Release_Component();


public :
	virtual HRESULT	Init()			PURE;
	virtual int		Update()		PURE;
	virtual void	Render()		PURE;
	virtual void	Release()		PURE;

protected:
	explicit CObj(ID3D11Device* _pDevice);
public :
	virtual ~CObj();
};

#endif // Obj_h__
