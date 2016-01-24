#include "stdafx.h"
#include "Obj.h"

#include "Component.h"


CObj::CObj(CDevice* _pDevice) :
m_pDevice(_pDevice),
m_eObjState(OBJ_STATE_NONE)
{

}

CObj::~CObj()
{
	Release_Component();
}

const CComponent* CObj::GetComponent(const wstring& _wstrComponentKey)
{
	map<wstring, CComponent*>::iterator iter = m_mapComponent.find(_wstrComponentKey);

	if (iter == m_mapComponent.end())
		return NULL;

	return iter->second;
}

void CObj::Update_Component()
{
	map<wstring, CComponent*>::iterator iter = m_mapComponent.begin();
	map<wstring, CComponent*>::iterator iter_end = m_mapComponent.end();

	for (; iter != iter_end; ++iter)
		iter->second->Update();
}

void CObj::Release_Component()
{
	for_each(m_mapComponent.begin(), m_mapComponent.end(), DeleteMap());
	m_mapComponent.clear();
}




