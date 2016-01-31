#include "stdafx.h"
#include "Buffer.h"

#include "Struct.h"


CBuffer::CBuffer(CDevice* _pDevice)
: CResource(_pDevice)
, m_pRasterizerState(NULL)

, m_pVtxBuffer(NULL)
, m_nVtxNum(0)
, m_nVtxByte(0)
, m_nVtxOffset(0)

, m_pIdxBuffer(NULL)
, m_nIdxNum(0)
, m_nStartIdx(0)
, m_nPlusIdx(0)
{

}

CBuffer::~CBuffer()
{

}

void CBuffer::Render()
{
	if (NULL == m_pVtxBuffer)
		return;

	ID3D11DeviceContext* pDeviceContext = m_pDevice->GetDeviceCon();
	pDeviceContext->IASetVertexBuffers(0, 1, &m_pVtxBuffer, &m_nVtxByte, &m_nVtxOffset);
	pDeviceContext->IASetIndexBuffer(m_pIdxBuffer, DXGI_FORMAT_R32_UINT, 0);
	pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	if (m_pRasterizerState)
		pDeviceContext->RSSetState(m_pRasterizerState);

	pDeviceContext->DrawIndexed(m_nIdxNum, m_nStartIdx, m_nPlusIdx);
	pDeviceContext->Draw((UINT)m_nVtxNum, (UINT)m_nVtxOffset);
}

void CBuffer::CreateRasterizerState()
{
	D3D11_RASTERIZER_DESC tRasterizerDest;
	ZeroMemory(&tRasterizerDest, sizeof(D3D11_RASTERIZER_DESC));
	tRasterizerDest.CullMode = D3D11_CULL_BACK;
	tRasterizerDest.FillMode = D3D11_FILL_WIREFRAME;
	m_pDevice->GetDevice()->CreateRasterizerState(&tRasterizerDest, &m_pRasterizerState);
}

void CBuffer::ReleaseBuffer()
{
	if((*m_pRefCnt) == 0)
	{
		::Safe_Release(m_pVtxBuffer);
		::Safe_Release(m_pIdxBuffer);

		::Safe_Delete(m_pVtxBuffer);
		::Safe_Delete(m_pIdxBuffer);
		CResource::ReleaseRefCnt();
	}
	else --(*m_pRefCnt);
}

