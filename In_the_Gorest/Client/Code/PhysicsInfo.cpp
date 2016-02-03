#include "stdafx.h"
#include "PhysicsInfo.h"


CPhysicsInfo::CPhysicsInfo(CDevice* _pDevice)
: m_pDevice(_pDevice)
, m_pWorldBuffer(NULL)

,m_vPos(0.f, 0.f, 0.f)
, m_vDir(0.f, 0.f, 0.f)

, m_fSpeed(0.f)
, m_fAccel(0.f)
, m_fWeight(0.f)
{
	ZeroMemory(&m_fRadian, sizeof(float)* RADIAN_END);
	D3DXMatrixIdentity(&m_matWorld);

	Init_WorldBuffer();
}

CPhysicsInfo::~CPhysicsInfo()
{
	Release();
}

void CPhysicsInfo::Init_WorldBuffer()
{
	D3D11_BUFFER_DESC tBuffer;
	ZeroMemory(&tBuffer, sizeof(D3D11_BUFFER_DESC));
	tBuffer.Usage = D3D11_USAGE_DYNAMIC;
	tBuffer.ByteWidth = sizeof(Buffer_World);
	tBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	tBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	FAILED_CHECK_RETURN(
		m_pDevice->GetDevice()->CreateBuffer(&tBuffer, NULL, &m_pWorldBuffer), );
}

CComponent* CPhysicsInfo::Create(CDevice* _pDevice)
{
	return new CPhysicsInfo(_pDevice);
}

void CPhysicsInfo::Update()
{
	D3DXMATRIX	matRotate, matTrans;
	D3DXMatrixRotationYawPitchRoll(&matRotate,
		m_fRadian[RADIAN_Y], m_fRadian[RADIAN_X], m_fRadian[RADIAN_Z]);
	D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y, m_vPos.z);

	m_matWorld = matRotate * matTrans;


	D3D11_MAPPED_SUBRESOURCE tSubreResource;
	ID3D11DeviceContext* pDeviceContext = m_pDevice->GetDeviceContext();
	pDeviceContext->Map(m_pWorldBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &tSubreResource);

	Buffer_World* pMatWorld = (Buffer_World*)tSubreResource.pData;
	D3DXMatrixTranspose(&pMatWorld->m_matWorld, &m_matWorld);

	pDeviceContext->Unmap(m_pWorldBuffer, 0);
	pDeviceContext->VSSetConstantBuffers(VS_SLOT_WORLD_MATRIX, 1, &m_pWorldBuffer);
}

void CPhysicsInfo::Release()
{
	::Safe_Release(m_pWorldBuffer);
}

