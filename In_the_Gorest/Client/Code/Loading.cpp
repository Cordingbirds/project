#include "stdafx.h"
#include "Loading.h"


CLoading::CLoading(ID3D11Device* _pDevice) :
CScene(_pDevice)
{
}


CLoading::~CLoading()
{
}

CLoading* CLoading::Create(ID3D11Device* _pDevice)
{
	CLoading* pScene = new CLoading(_pDevice);

	if (FAILED(pScene->Init()))
		Safe_Delete(pScene);

	return pScene;
}

HRESULT CLoading::Init()
{
	return S_OK;
}

void CLoading::Update()
{

}

void CLoading::Render()
{

}

void CLoading::Release()
{

}

