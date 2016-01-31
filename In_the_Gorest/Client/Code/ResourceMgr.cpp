#include "stdafx.h"
#include "ResourceMgr.h"

#include "CubeBuffer.h"
#include "Functor.h"

IMPLEMENT_SINGLETON(CResourceMgr)


CResourceMgr::CResourceMgr()
{

}

CResourceMgr::~CResourceMgr()
{
	Release_All();
}

CResource* CResourceMgr::FindResource(ResourceType _eResourceType, const wstring& _wstrKey)
{
	map<wstring, CResource*>::iterator iter = m_mapResource[_eResourceType].find(_wstrKey);

	if (iter == m_mapResource[_eResourceType].end())
	{
		TAGMSG_BOX(_wstrKey.c_str(), L"리소스 원형이 존재하지 않습니다.");
		return NULL;
	}

	return iter->second;
}

CResource* CResourceMgr::CloneResource(ResourceType _eResourceType, const wstring& _wstrKey)
{
	map<wstring, CResource*>::iterator iter = m_mapResource[_eResourceType].find(_wstrKey);

	if (iter == m_mapResource[_eResourceType].end())
	{
		TAGMSG_BOX(_wstrKey.c_str(), L"리소스 원형이 존재하지 않습니다.");
		return NULL;
	}

	return iter->second->Clone();
}

HRESULT CResourceMgr::AddBuffer(CDevice* _pDevice, BufferType _eBufferType, ResourceType _eResourceType, const wstring& _wstrKey)
{
	map<wstring, CResource*>::iterator iter = m_mapResource[_eResourceType].find(_wstrKey);

	if (iter != m_mapResource[_eResourceType].end())
	{
		return S_OK;
	}

	CResource*		pResource = NULL;

	switch (_eBufferType)
	{
		case BUFFER_TYPE_CUBE :
			pResource = CCubeBuffer::Create(_pDevice);
			break;
	}

	NULL_CHECK_RETURN(pResource, E_FAIL);

	m_mapResource[_eResourceType].insert(make_pair(_wstrKey, pResource));
	return S_OK;
}

HRESULT CResourceMgr::AddTexture(CDevice* _pDevice, ResourceType _eResourceType, const wstring& _wstrKey, const wstring& _wstrPath, const DWORD& dwCnt /*= 1*/)
{
	map<wstring, CResource*>::iterator iter = m_mapResource[_eResourceType].find(_wstrKey);

	if (iter != m_mapResource[_eResourceType].end())
	{
		return S_OK;
	}

	// (수정)
	return E_FAIL;
}

HRESULT CResourceMgr::AddMesh() // (수정)
{
	// (수정)
	return E_FAIL;
}

void CResourceMgr::Release_Dynamic()
{
	for_each(m_mapResource[RESOURCE_TYPE_DYNAMIC].begin(),
		m_mapResource[RESOURCE_TYPE_DYNAMIC].end(), ::DeleteMap());
	m_mapResource[RESOURCE_TYPE_DYNAMIC].clear();
}

void CResourceMgr::Release_All()
{
	for (int i = 0; i < RESOURCE_TYPE_END; ++i)
	{
		for_each(m_mapResource[i].begin(), m_mapResource[i].end(), ::DeleteMap());
		m_mapResource[i].clear();
	}
}
