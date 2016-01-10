#include "stdafx.h"
#include "Title.h"


CTitle::CTitle(ID3D11Device* _pDevice) :
CScene(_pDevice)
{
}

CTitle::~CTitle()
{
}

CTitle* CTitle::Create(ID3D11Device* _pDevice)
{
	CTitle* pScene = new CTitle(_pDevice);

	if (FAILED(pScene->Init()))
		Safe_Delete(pScene);

	return pScene;
}

HRESULT CTitle::Init()
{
	return S_OK;
}

void CTitle::Update()
{

}

void CTitle::Render()
{

}

void CTitle::Release()
{

}
