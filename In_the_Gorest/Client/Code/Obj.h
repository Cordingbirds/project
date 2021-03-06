/*!
 * \file Obj.h
 * \date 2016/01/11 4:10
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

#ifndef Obj_h__
#define Obj_h__

#include "Include.h"


class CDevice;
class CComponent;
class CObj
{
public :
	static enum ObjState
	{
		OBJ_STATE_NONE,

		OBJ_STATE_IDLE,
		OBJ_STATE_ALIVE,
		OBJ_STATE_DIE
	};

protected:
	CDevice*			m_pDevice;
	ObjState			m_eObjState;

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
	explicit CObj(CDevice* _pDevice);
public :
	virtual ~CObj();
};

#endif // Obj_h__
