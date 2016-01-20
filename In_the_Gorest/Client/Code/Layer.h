/*!
* \file Layer.cpp
* \date 2016/01/11 3:16
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

#ifndef Layer_h__
#define Layer_h__

class CObj;
class CComponent;
class CLayer
{
private :
	ID3D11Device*				m_pDevice;
	map<wstring, list<CObj*>>	m_mapObjList;

public :
	static CLayer*		Create(ID3D11Device* _pDevice);
	HRESULT				AddObj(const wstring& _wstrObjKey, CObj* _pObj);	
	const CComponent*	GetComponent(const wstring& _wstrObjKey, const wstring& _wstrComponentKey);

	map<wstring, list<CObj*>>* GetMapObjList() { return &m_mapObjList; }


public :
	void	Update_Obj();
	void	Render_Obj();
private :
	void	Release_Obj();


private:
	explicit CLayer(ID3D11Device* _pDevice);
public:
	~CLayer();
};

#endif // Layer_h__
