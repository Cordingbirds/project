#include "stdafx.h"
#include "BoxCol.h"

#include "ResourceMgr.h"
#include "CubeBuffer.h"

#include "PhysicsInfo.h"


CBoxCol::CBoxCol(CDevice* _pDevice)
: CCollision(_pDevice)

, m_pBuffer(NULL)

, m_pOwnerPos(NULL)
, m_vPlusPos(0.f, 0.f, 0.f)
, m_vScale(1.f, 1.f, 1.f)
{

}

CBoxCol::~CBoxCol()
{
	Release();
}

CComponent* CBoxCol::Create(CDevice* _pDevice)
{
	CComponent* pComponent = new CBoxCol(_pDevice);
	if ( FAILED((dynamic_cast<CBoxCol*>(pComponent)->Init())) )
		::Safe_Delete(pComponent);

	return pComponent;
}

HRESULT CBoxCol::Init()
{
	m_pBuffer = dynamic_cast<CBuffer*>(CResourceMgr::GetInstance()->
		CloneResource(CResourceMgr::RESOURCE_TYPE_DYNAMIC, L"CubeColor"));
	NULL_CHECK_RETURN(m_pBuffer, E_FAIL);


	D3D11_BUFFER_DESC tBuffer;
	ZeroMemory(&tBuffer, sizeof(D3D11_BUFFER_DESC));
	tBuffer.Usage = D3D11_USAGE_DYNAMIC;
	tBuffer.ByteWidth = sizeof(D3DXMATRIX);
	tBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	tBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	FAILED_CHECK_RETURN(
		m_pDevice->GetDevice()->CreateBuffer(&tBuffer, NULL, &m_pWorldBuffer), S_FALSE);

	return S_OK;
}

void CBoxCol::Update()
{
	D3DXMATRIX	matScale, matTrans, matWolrd;
	D3DXMatrixScaling(&matScale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(
		&matTrans,
		m_pOwnerPos->x + m_vPlusPos.x,
		m_pOwnerPos->y + m_vPlusPos.y,
		m_pOwnerPos->z + m_vPlusPos.z);

	matWolrd = matScale * matTrans;

	D3D11_MAPPED_SUBRESOURCE tSubreResource;
	ID3D11DeviceContext* pDeviceContext = m_pDevice->GetDeviceContext();
	pDeviceContext->Map(m_pWorldBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &tSubreResource);

	Buffer_World* pMatWorld = (Buffer_World*)(tSubreResource.pData);
	D3DXMatrixTranspose(&pMatWorld->m_matWorld, &matWolrd);

	pDeviceContext->Unmap(m_pWorldBuffer, 0);
	pDeviceContext->VSSetConstantBuffers(VS_SLOT_WORLD_MATRIX, 1, &m_pWorldBuffer);

	m_pBuffer->Update();
}

void CBoxCol::Render()
{
	m_pBuffer->Render();
}

void CBoxCol::Release()
{
	::Safe_Delete(m_pBuffer);
	::Safe_Release(m_pWorldBuffer);
}
