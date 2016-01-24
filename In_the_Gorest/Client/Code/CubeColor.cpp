#include "stdafx.h"
#include "CubeColor.h"

#include "Struct.h"
#include "Function.h"


CCubeColor::CCubeColor(CDevice* _pDevice) :
CBuffer(_pDevice)
{
	
}

CCubeColor::~CCubeColor()
{
	Release();
}

CComponent* CCubeColor::Create(CDevice* _pDevice)
{
	CCubeColor* pComponent = new CCubeColor(_pDevice);
	if (FAILED(pComponent->Init()))
		::Safe_Delete(pComponent);

	return pComponent;
}

CComponent* CCubeColor::Clone()
{
	++(*m_pRefCnt);
	return new CCubeColor(*this);
}

HRESULT CCubeColor::Init()
{
	m_nVtxNum		= 8;
	m_nVtxByte		= sizeof(VertexColor) * 8;
	m_nVtxOffset	= 0;

	m_nIdxNum		= 12;
	m_nStartIdx		= 0;
	m_nPlusIdx		= 0;

	Init_Vtx();
	Init_Idx();
	CreateRasterizerState();

	return S_OK;
}

void CCubeColor::Init_Vtx()
{
	VertexColor* pVertex = NULL;

	pVertex[0].vPos = D3DXVECTOR3(-1.f, 1.f, -1.f);
	pVertex[0].vColor = D3DXVECTOR4(0.f, 1.f, 0.f, 1.f);
	pVertex[0].vNormal = D3DXVECTOR3(1.f, 1.f, 1.f);

	pVertex[1].vPos = D3DXVECTOR3(1.f, 1.f, -1.f);
	pVertex[1].vColor = D3DXVECTOR4(0.f, 1.f, 0.f, 1.f);
	pVertex[1].vNormal = D3DXVECTOR3(1.f, 1.f, 1.f);

	pVertex[2].vPos = D3DXVECTOR3(1.f, -1.f, -1.f);
	pVertex[2].vColor = D3DXVECTOR4(0.f, 1.f, 0.f, 1.f);
	pVertex[2].vNormal = D3DXVECTOR3(1.f, 1.f, 1.f);

	pVertex[3].vPos = D3DXVECTOR3(-1.f, -1.f, -1.f);
	pVertex[3].vColor = D3DXVECTOR4(0.f, 1.f, 0.f, 1.f);
	pVertex[3].vNormal = D3DXVECTOR3(1.f, 1.f, 1.f);

	pVertex[4].vPos = D3DXVECTOR3(-1.f, 1.f, 1.f);
	pVertex[4].vColor = D3DXVECTOR4(0.f, 1.f, 0.f, 1.f);
	pVertex[4].vNormal = D3DXVECTOR3(1.f, 1.f, 1.f);

	pVertex[5].vPos = D3DXVECTOR3(1.f, 1.f, 1.f);
	pVertex[5].vColor = D3DXVECTOR4(0.f, 1.f, 0.f, 1.f);
	pVertex[5].vNormal = D3DXVECTOR3(1.f, 1.f, 1.f);

	pVertex[6].vPos = D3DXVECTOR3(1.f, -1.f, 1.f);
	pVertex[6].vColor = D3DXVECTOR4(0.f, 1.f, 0.f, 1.f);
	pVertex[6].vNormal = D3DXVECTOR3(1.f, 1.f, 1.f);

	pVertex[7].vPos = D3DXVECTOR3(-1.f, -1.f, 1.f);
	pVertex[7].vColor = D3DXVECTOR4(0.f, 1.f, 0.f, 1.f);
	pVertex[7].vNormal = D3DXVECTOR3(1.f, 1.f, 1.f);


	D3D11_BUFFER_DESC tBufferDesc;
	ZeroMemory(&tBufferDesc, sizeof(D3D11_BUFFER_DESC));
	tBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	tBufferDesc.ByteWidth = m_nVtxByte;
	tBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	tBufferDesc.CPUAccessFlags = 0;
	tBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA tData;
	ZeroMemory(&tData, sizeof(D3D11_SUBRESOURCE_DATA));
	tData.pSysMem = pVertex;
	m_pDevice->GetDevice()->CreateBuffer(&tBufferDesc, &tData, &m_pVtxBuffer);
}

void CCubeColor::Init_Idx()
{
	Index32* pIdx	= NULL;

	// Front
	pIdx[0]._1 = 0;		pIdx[0]._2 = 1;		pIdx[0]._3 = 2;
	pIdx[1]._1 = 0;		pIdx[1]._2 = 2;		pIdx[1]._3 = 3;

	// Right
	pIdx[2]._1 = 1;		pIdx[2]._2 = 5;		pIdx[2]._3 = 6;
	pIdx[3]._1 = 1;		pIdx[3]._2 = 6;		pIdx[3]._3 = 2;

	// Bottom
	pIdx[4]._1 = 3;		pIdx[4]._2 = 2;		pIdx[4]._3 = 6;
	pIdx[5]._1 = 3;		pIdx[5]._2 = 6;		pIdx[5]._3 = 7;

	// Left
	pIdx[6]._1 = 4;		pIdx[6]._2 = 0;		pIdx[6]._3 = 3;
	pIdx[7]._1 = 4;		pIdx[7]._2 = 3;		pIdx[7]._3 = 7;

	// Top
	pIdx[8]._1 = 4;		pIdx[8]._2 = 5;		pIdx[8]._3 = 1;
	pIdx[9]._1 = 4;		pIdx[9]._2 = 1;		pIdx[9]._3 = 0;

	// Back
	pIdx[10]._1 = 5;	pIdx[10]._2 = 4;	pIdx[10]._3 = 7;
	pIdx[11]._1 = 5;	pIdx[11]._2 = 7;	pIdx[11]._3 = 6;


	D3D11_BUFFER_DESC tBufferDesc;
	ZeroMemory(&tBufferDesc, sizeof(D3D11_BUFFER_DESC));
	tBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	tBufferDesc.ByteWidth = sizeof(Index32)* m_nIdxNum;
	tBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	tBufferDesc.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA tData;
	ZeroMemory(&tData, sizeof(D3D11_SUBRESOURCE_DATA));
	tData.pSysMem = pIdx;
	m_pDevice->GetDevice()->CreateBuffer(&tBufferDesc, &tData, &m_pIdxBuffer);
}


void CCubeColor::Update()
{

}

void CCubeColor::Release()
{

}

