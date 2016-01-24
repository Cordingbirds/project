#include "stdafx.h"
#include "ObjMgr.h"

#include "Obj.h"

IMPLEMENT_SINGLETON(CObjMgr)


CObjMgr::CObjMgr()
{

}

CObjMgr::~CObjMgr()
{
	Release();
}

void CObjMgr::AddObj(const wstring& _wstrObjKey, CObj* _pObj)
{
	if (_pObj == NULL)
		return;

	map<wstring, ListObj>::iterator iter_find = (*m_pMapObjList).find(_wstrObjKey);

	if (iter_find == (*m_pMapObjList).end())
		((*m_pMapObjList)[_wstrObjKey]) = ListObj();

	((*m_pMapObjList)[_wstrObjKey]).push_back(_pObj);
}

void CObjMgr::Release()
{
	m_pMapObjList = NULL;
}

