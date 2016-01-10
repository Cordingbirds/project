#include "stdafx.h"
#include "Room.h"


CRoom::CRoom(ID3D11Device* _pDevice) :
CScene(_pDevice)
{
}


CRoom::~CRoom()
{
}

CRoom* CRoom::Create(ID3D11Device* _pDevice)
{
	CRoom* pScene = new CRoom(_pDevice);

	if (FAILED(pScene->Init()))
		Safe_Delete(pScene);

	return pScene;
}

HRESULT CRoom::Init()
{
	return S_OK;
}

void CRoom::Update()
{

}

void CRoom::Render()
{

}

void CRoom::Release()
{

}
