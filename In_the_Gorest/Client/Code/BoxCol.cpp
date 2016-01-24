#include "stdafx.h"
#include "BoxCol.h"

#include "Function.h"

#include "CubeColor.h"


CBoxCol::CBoxCol(CDevice* _pDevice)
: CCollision(_pDevice)

, m_pBuffer(NULL)

, m_pOwnerPos(NULL)
, m_vPlusPos(0.f, 0.f, 0.f)
, m_vScale(0.f, 0.f, 0.f)
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
	//m_pBuffer = dynamic_cast<CCubeColor*>(CCubeColor::Clone());
	//NULL_CHECK_RETURN(m_pBuffer, S_FALSE);
	// 리소스 매니저 만들어서 CubeColor을 Clone 해야함 (수정)


	return S_OK;
}

void CBoxCol::Update()
{

}

void CBoxCol::Render()
{
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);

	//
}

void CBoxCol::Release()
{
	::Safe_Delete(m_pBuffer);
}
