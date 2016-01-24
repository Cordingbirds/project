#include "stdafx.h"
#include "PhysicsInfo.h"

CPhysicsInfo::CPhysicsInfo()
: m_vPos(0.f, 0.f, 0.f)
, m_vDir(0.f, 0.f, 0.f)

, m_fSpeed(0.f)
, m_fAccel(0.f)
, m_fWeight(0.f)
{
	ZeroMemory(&m_fRadian, sizeof(float)* RADIAN_END);
	D3DXMatrixIdentity(&m_matWorld);
}

CPhysicsInfo::~CPhysicsInfo()
{
	Release();
}

CComponent* CPhysicsInfo::Create()
{
	return new CPhysicsInfo;
}

void CPhysicsInfo::Update()
{
	D3DXMATRIX	matRotate, matTrans;
	D3DXMatrixRotationYawPitchRoll(&matRotate,
		m_fRadian[RADIAN_Y], m_fRadian[RADIAN_X], m_fRadian[RADIAN_Z]);
	D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y, m_vPos.z);

	m_matWorld = matRotate * matTrans;
}

void CPhysicsInfo::Release()
{
}
