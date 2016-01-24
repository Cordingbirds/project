/*!
 * \file InfoSubject.h
 * \date 2016/01/11 6:10
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

#ifndef InfoSubject_h__
#define InfoSubject_h__

#include "Subject.h"
#include "Define.h"

class CInfoSubject : public CSubject
{
	DECLARE_SINGLETON(CInfoSubject)

private :
	map<int, list<void*>>		m_mapDataList;


public:
	list<void*>* GetDatalist(int _imessage);

public:
	void AddData(int _iMessage, void* _pData);
	void RemoveData(int _iMessage, void* _pData);

private:
	void Release(void);


private :
	CInfoSubject();
	virtual ~CInfoSubject();
};

#endif // InfoSubject_h__
