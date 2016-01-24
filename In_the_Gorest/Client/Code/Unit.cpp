#include "stdafx.h"
#include "Unit.h"

#include "Component.h"


CUnit::CUnit(CDevice* _pDevice)
: CObj(_pDevice)
{
	CreateWorldMarixBuffer(_pDevice);
	AddComponent();
}

CUnit::~CUnit()
{

}

void CUnit::CreateWorldMarixBuffer(CDevice* _pDevice)
{
	D3D11_BUFFER_DESC tBuffer;
	ZeroMemory(&tBuffer, sizeof(D3D11_BUFFER_DESC));
	tBuffer.Usage = D3D11_USAGE_DYNAMIC;
	tBuffer.ByteWidth = sizeof(D3DXMATRIX);
	tBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	tBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	_pDevice->GetDevice()->CreateBuffer(&tBuffer, NULL, &m_pWorldMarixBuffer);
}

void CUnit::AddComponent()
{
	// PhysicsInfo ------------
	m_pPhysicsInfo = dynamic_cast<CPhysicsInfo*>(CPhysicsInfo::Create());
	NULL_CHECK(m_pPhysicsInfo);
	m_mapComponent.insert(make_pair(L"PhysicsInfo", m_pPhysicsInfo));

	// BoxCol ---------------
	m_pBoxCol = dynamic_cast<CBoxCol*>(CBoxCol::Create(m_pDevice));
	NULL_CHECK(m_pBoxCol);
	m_mapComponent.insert(make_pair(L"BoxCol", m_pPhysicsInfo));
}

