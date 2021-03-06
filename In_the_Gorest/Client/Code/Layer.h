/*!
* \file Layer.cpp
* \date 2016/01/11 3:16
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

#ifndef Layer_h__
#define Layer_h__

class CDevice;
class CObj;
class CComponent;
class CLayer
{
public :
	static enum LayerType
	{
		LAYERTYPE_ENVIRONMENT,
		LAYERTYPE_GAMELOGIC,
		LAYERTYPE_UI,

		LAYERTYPE_END
	};

private :
	CDevice*				m_pDevice;
	map<wstring, list<CObj*>>	m_mapObjList;

public :
	static CLayer*		Create(CDevice* _pDevice);
	HRESULT				AddObj(const wstring& _wstrObjKey, CObj* _pObj);	
	const CComponent*	GetComponent(const wstring& _wstrObjKey, const wstring& _wstrComponentKey);

	map<wstring, list<CObj*>>*	GetMapObjList()		{ return &m_mapObjList; }


public :
	void	Update_Obj();
	void	Render_Obj();
private :
	void	Release_Obj();


private:
	explicit CLayer(CDevice* _pDevice);
public:
	~CLayer();
};

#endif // Layer_h__
