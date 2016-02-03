/*!
 * \file ObjMgr.h
 * \date 2016/01/25 3:17
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

#ifndef ObjMgr_h__
#define ObjMgr_h__

#include "Define.h"

class CObj;
typedef list<CObj*> ListObj;
class CObjMgr
{
	DECLARE_SINGLETON(CObjMgr)

private:
	map<wstring, ListObj>*		m_pMapObjList;


public :
	void SetMapObjList(map<wstring, ListObj>* _pMapObjList)		{ m_pMapObjList = _pMapObjList; }
	void AddObj(const wstring& _wstrObjKey, CObj* _pObj);

public :
	void Release();

private :
	CObjMgr();
	~CObjMgr();
};


#endif // ObjMgr_h__
