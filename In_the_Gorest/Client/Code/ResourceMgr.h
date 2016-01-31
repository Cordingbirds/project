/*!
* \file ResourceMgr.h
* \date 2016/01/31 6:16
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

/*
���� ���ҽ��� ����� �ִ� Ŭ�����Դϴ�.
�ε��� �� �� �ش���� �ʿ��� ���ҽ� ������ m_mapResource �� Add ���ֽð�,
�ش� ���ҽ��� Ŭ���ϰ� ���� ��� m_mapResource ���� ���ҽ��� Find �� ��
���� �Ǵ� ���� ���ҽ��� Ŭ���Լ��� ȣ���ϸ� �˴ϴ�.
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
