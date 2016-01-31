#include "stdafx.h"
#include "Layer.h"

#include "Obj.h"


CLayer::CLayer(CDevice* _pDevice)
: m_pDevice(_pDevice)
{

}

CLayer::~CLayer()
{
	Release_Obj();
}

CLayer* CLayer::Create(CDevice* _pDevice)
{
	return new CLayer(_pDevice);
}

HRESULT CLayer::AddObj(const wstring& _wstrObjKey, CObj* _pObj)
{
	if (_pObj)
	{
		map<wstring, list<CObj*>>::iterator iter = m_mapObjList.find(_wstrObjKey);

		if (iter == m_mapObjList.end())
			m_mapObjList[_wstrObjKey] = list<CObj*>();

		m_mapObjList[_wstrObjKey].push_back(_pObj);
	}
	else return E_FAIL;

	return S_OK;
}

const CComponent* CLayer::GetComponent(const wstring& _wstrObjKey, const wstring& _wstrComponentKey)
{
	map<wstring, list<CObj*>>::iterator	iterMap = m_mapObjList.find(_wstrObjKey);

	if (iterMap == m_mapObjList.end())
		return NULL;

	list<CObj*>::iterator	iterList		= iterMap->second.begin();
	list<CObj*>::iterator	iterList_end	= iterMap->second.end();

	for (; iterList != iterList_end; ++iterList)
	{
		const CComponent* pComponent = (*iterList)->GetComponent(_wstrComponentKey);

		if (pComponent != NULL)
			return pComponent;
	}
	return NULL;
}

void CLayer::Update_Obj()
{
	map<wstring, list<CObj*>>::iterator	iterMap = m_mapObjList.begin();
	map<wstring, list<CObj*>>::iterator iterMap_end = m_mapObjList.end();

	for (; iterMap != iterMap_end; ++iterMap)
	{
		list<CObj*>::iterator	iterList = iterMap->second.begin();
		list<CObj*>::iterator	iterList_end = iterMap->second.end();

		for (; iterList != iterList_end;)
		{
			if ((*iterList)->Update() == CObj::OBJ_STATE_DIE)
			{
				::Safe_Delete(*iterList);
				iterList = iterMap->second.erase(iterList);
			}
			else ++iterList;
		}
	}
}

void CLayer::Render_Obj()
{
	map<wstring, list<CObj*>>::iterator	iterMap = m_mapObjList.begin();
	map<wstring, list<CObj*>>::iterator iterMap_end = m_mapObjList.end();

	for (; iterMap != iterMap_end; ++iterMap)
	{
		list<CObj*>::iterator	iterList = iterMap->second.begin();
		list<CObj*>::iterator	iterList_end = iterMap->second.end();

		for (; iterList != iterList_end; ++iterList)
			(*iterList)->Render();
	}
}

void CLayer::Release_Obj()
{
	map<wstring, list<CObj*>>::iterator	iterMap = m_mapObjList.begin();
	map<wstring, list<CObj*>>::iterator iterMap_end = m_mapObjList.end();

	for (; iterMap != iterMap_end; ++iterMap)
	{
		list<CObj*>::iterator	iterList = iterMap->second.begin();
		list<CObj*>::iterator	iterList_end = iterMap->second.end();

		for (; iterList != iterList_end; ++iterList)
			::Safe_Delete(*iterList);

		iterMap->second.clear();
	}
	m_mapObjList.clear();
}


