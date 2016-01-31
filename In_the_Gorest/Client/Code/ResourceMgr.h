/*!
* \file ResourceMgr.h
* \date 2016/01/31 6:16
*
* \author 김명지
* Contact: bluevill04@gmail.com
*
* \brief
*
* TODO: long description
*
* \note
*/

/*
원형 리소스가 담겨져 있는 클래스입니다.
로딩을 할 때 해당씬에 필요한 리소스 원형을 m_mapResource 에 Add 해주시고,
해당 리소스를 클론하고 싶을 경우 m_mapResource 에서 리소스를 Find 한 후
리턴 되는 원형 리소스의 클론함수를 호출하면 됩니다.
*/

#pragma once

#ifndef ResourceMgr_h__
#define ResourceMgr_h__

class CResource;
class CDevice;
class CResourceMgr
{
	DECLARE_SINGLETON(CResourceMgr)

public :
public:
	static enum BufferType
	{
		BUFFER_TYPE_CUBE,

		BUFFER_TYPE_END
	};

	static enum ResourceType
	{
		RESOURCE_TYPE_STATIC,
		RESOURCE_TYPE_DYNAMIC,

		RESOURCE_TYPE_END
	};

private:
	map<wstring, CResource*>		m_mapResource[RESOURCE_TYPE_END];


public:
	CResource*		FindResource(ResourceType _eResourceType, const wstring& _wstrKey);
	CResource*		CloneResource(ResourceType _eResourceType, const wstring& _wstrKey);

	HRESULT			AddBuffer(CDevice* _pDevice, BufferType _eBufferType,
						ResourceType _eResourceType, const wstring& _wstrKey);
	HRESULT			AddTexture(CDevice* _pDevice, ResourceType _eResourceType,
						const wstring& _wstrKey, const wstring& _wstrPath, const DWORD& dwCnt = 1);
	HRESULT			AddMesh();

public :
	void	Release_Dynamic();
	void	Release_All();


private:
	CResourceMgr();
	~CResourceMgr();
};

#endif // ResourceMgr_h__
