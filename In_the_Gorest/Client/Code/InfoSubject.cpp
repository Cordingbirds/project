#include "stdafx.h"
#include "InfoSubject.h"

CInfoSubject::CInfoSubject()
{

}


CInfoSubject::~CInfoSubject()
{
	Release();
}

list<void*>* CInfoSubject::GetDatalist(int _imessage)
{
	map<int, list<void*>>::iterator	iter = m_mapDataList.find(_imessage);

	if (iter == m_mapDataList.end())
		return NULL;

	return &iter->second;
}

void CInfoSubject::AddData(int _iMessage, void* _pData)
{
	if (_pData)
	{
		map<int, list<void*>>::iterator	iter = m_mapDataList.find(_iMessage);
		if (iter == m_mapDataList.end())
		{
			m_mapDataList[_iMessage] = list<void*>();
		}
		m_mapDataList[_iMessage].push_back(_pData);
	}
}

void CInfoSubject::RemoveData(int _iMessage, void* _pData)
{
	map<int, list<void*>>::iterator	iterMap = m_mapDataList.find(_iMessage);
	if (iterMap != m_mapDataList.end())
	{
		list<void*>::iterator iterList		= iterMap->second.begin();
		list<void*>::iterator iterList_end	= iterMap->second.end();

		for (; iterList != iterList_end; ++iterList)
		{
			if ((*iterList) == _pData)
			{
				iterMap->second.erase(iterList);
				return;
			}
		}
	}
}

void CInfoSubject::Release(void)
{
	map<int, list<void*>>::iterator iter = m_mapDataList.begin();

	for (; iter != m_mapDataList.end(); ++iter)
		iter->second.clear();
	m_mapDataList.clear();
}


