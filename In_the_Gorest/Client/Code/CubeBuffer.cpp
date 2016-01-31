#include "stdafx.h"
#include "CubeBuffer.h"

#include "ColorShader.h"
#include "Struct.h"
#include "Function.h"


CCubeBuffer::CCubeBuffer(CDevice* _pDevice)
: CBuffer(_pDevice)
, m_pColorShader(NULL)
{
	
}

CCubeBuffer::~CCubeBuffer()
{
	Release();
}

CResource* CCubeBuffer::Create(CDevice* _pDevice)
{
	CCubeBuffer* pComponent = new CCubeBuffer(_pDevice);
	if (FAILED(pComponent->Init()))
		::Safe_Delete(pComponent);

	pComponent->m_pColorShader
		= dynamic_cast<CColorShader*>(CColorShader::Create(_pDevice));

	return pComponent;
}

CResource* CCubeBuffer::Clone()
{
	++(*m_pRefCnt);
	return new CCubeBuffer(*this);
}

HRESULT CCubeBuffer::Init()
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

void CCubeBuffer::Init_Vtx()
{
	VertexColor pVertex[] =
	{
		{ D3DXVECTOR3(-1.f, 1.f, -1.f)
		, D3DXVECTOR4(0.f, 1.f, 0.f, 1.f) },

		{ D3DXVECTOR3(1.f, 1.f, -1.f)
		, D3DXVECTOR4(0.f, 1.f, 0.f, 1.f) },

		{ D3DXVECTOR3(1.f, -1.f, -1.f)
		, D3DXVECTOR4(0.f, 1.f, 0.f, 1.f) },

		{ D3DXVECTOR3(-1.f, -1.f, -1.f)
		, D3DXVECTOR4(0.f, 1.f, 0.f, 1.f) },

		{ D3DXVECTOR3(-1.f, 1.f, 1.f)
		, D3DXVECTOR4(0.f, 1.f, 0.f, 1.f) },

		{ D3DXVECTOR3(1.f, 1.f, 1.f)
		, D3DXVECTOR4(0.f, 1.f, 0.f, 1.f) },

		{ D3DXVECTOR3(1.f, -1.f, 1.f)
		, D3DXVECTOR4(0.f, 1.f, 0.f, 1.f) },

		{ D3DXVECTOR3(-1.f, -1.f, 1.f)
		, D3DXVECTOR4(0.f, 1.f, 0.f, 1.f) }
	};


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

void CCubeBuffer::Init_Idx()
{
	Index32 pIdx[] =
	{
		// Front
		{ Index32(0, 1, 2) },
		{ Index32(0, 2, 3) },

		// Right
		{ Index32(1, 5, 6) },
		{ Index32(1, 6, 2) },

		// Bottom
		{ Index32(3, 2, 6) },
		{ Index32(3, 6, 7) },

		// Left
		{ Index32(4, 0, 3) },
		{ Index32(4, 3, 7) },

		// Top
		{ Index32(4, 5, 1) },
		{ Index32(4, 1, 0) },

		// Back
		{ Index32(5, 4, 7) },
		{ Index32(5, 7, 6) },
	};


	D3D11_BUFFER_DESC tBufferDesc;
	ZeroMemory(&tBufferDesc, sizeof(D3D11_BUFFER_DESC));
	tBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	tBufferDesc.ByteWidth = sizeof(Index32) * m_nIdxNum;
	tBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	tBufferDesc.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA tData;
	ZeroMemory(&tData, sizeof(D3D11_SUBRESOURCE_DATA));
	tData.pSysMem = pIdx;
	m_pDevice->GetDevice()->CreateBuffer(&tBufferDesc, &tData, &m_pIdxBuffer);
}

void CCubeBuffer::Update()
{

}

void CCubeBuffer::Render()
{
	m_pColorShader->Render();
	CBuffer::Render();
}

void CCubeBuffer::Release()
{

}

