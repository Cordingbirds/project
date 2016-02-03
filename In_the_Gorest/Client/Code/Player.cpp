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

	m_pBoxCol->m_pOwnerPos = &(m_pPhysicsInfo->m_vPos);
	m_pBoxCol->m_vScale = D3DXVECTOR3(1.f, 1.f, 3.f);


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
	m_pBoxCol->Render();
}

void CPlayer::Release()
{

}

