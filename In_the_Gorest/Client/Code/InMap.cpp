#include "stdafx.h"
#include "InMap.h"


CInMap::CInMap(ID3D11Device* _pDevice)
: CScene(_pDevice)
{
}


CInMap::~CInMap()
{
}

CInMap* CInMap::Create(ID3D11Device* _pDevice)
{
	CInMap* pScene = new CInMap(_pDevice);

	if (FAILED(pScene->Init()))
		Safe_Delete(pScene);

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
