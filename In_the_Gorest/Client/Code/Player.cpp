#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer(CDevice* _pDevice)
: CRider(_pDevice)
{

}

CPlayer::~CPlayer()
{

}


CObj* CPlayer::Create(CDevice* _pDevice)
{
	CObj* pObj = new CPlayer(_pDevice);
	if (FAILED(pObj->Init()))
		::Safe_Delete(pObj);

	return pObj;
}

HRESULT CPlayer::Init()
{
	m_eObjState = CObj::OBJ_STATE_ALIVE;

	return S_OK;
}

int CPlayer::Update()
{
	switch (m_eObjState)
	{
	case CObj::OBJ_STATE_NONE :
		break;

	case CObj::OBJ_STATE_IDLE :
		break;

	case CObj::OBJ_STATE_ALIVE :
	{
		CObj::Update_Component();
		break;
	}

	case CObj::OBJ_STATE_DIE :
		break;
	}

	return m_eObjState;
}

void CPlayer::Render()
{
	//D3D11_MAPPED_SUBRESOURCE tmappedResiurce;
	//tmappedResiurce->Map(m_pWorldMarixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &tmappedResiurce);
	//m_pPhysicsInfo->m_matWorld = (D3DXMATRIX)tmappedResiurce.pData;

	//m_pDevice->GetDeviceCon()->VSSetConstantBuffers(
	// 상수 버퍼 (수정)
}

void CPlayer::Release()
{

}

