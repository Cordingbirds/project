#include "stdafx.h"
#include "Lobby.h"


CLobby::CLobby(ID3D11Device* _pDevice)
: CScene(_pDevice)
{
}


CLobby::~CLobby()
{
}

CLobby* CLobby::Create(ID3D11Device* _pDevice)
{
	CLobby* pScene = new CLobby(_pDevice);

	if (FAILED(pScene->Init()))
		Safe_Delete(pScene);

	return pScene;
}

HRESULT CLobby::Init()
{
	return S_OK;
}

void CLobby::Update()
{

}

void CLobby::Render()
{

}

void CLobby::Release()
{

}
