#include "stdafx.h"
#include "InMap.h"


CInMap::CInMap(CDevice* _pDevice)
: CScene(_pDevice)
{
}


CInMap::~CInMap()
{
}

CInMap* CInMap::Create(CDevice* _pDevice)
{
	CInMap* pScene = new CInMap(_pDevice);

	if (FAILED(pScene->Init()))
		::Safe_Delete(pScene);

	return pScene;
}

HRESULT CInMap::Init()
{
	return S_OK;
}

void CInMap::Update()
{

}

void CInMap::Render()
{

}

void CInMap::Release()
{

}
