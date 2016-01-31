#include "stdafx.h"
#include "ColorShader.h"


CColorShader::CColorShader(CDevice* _pDevice)
: CShader(_pDevice)
{

}

CColorShader::~CColorShader()
{
	Release();
}

CComponent* CColorShader::Create(CDevice* _pDevice)
{
	CComponent* pComponent = new CColorShader(_pDevice);
	if (FAILED((dynamic_cast<CColorShader*>(pComponent)->Init())))
		::Safe_Delete(pComponent);

	return pComponent;
}

HRESULT CColorShader::Init()
{
	D3D11_INPUT_ELEMENT_DESC tInputLayout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};
	UINT iElementNum = ARRAYSIZE(tInputLayout);


	DWORD swFlag =  D3DCOMPILE_ENABLE_STRICTNESS;

#if defined( DEBUG ) || defined( _DEBUG )
	swFlag |= D3D10_SHADER_DEBUG;
#endif

	ID3DBlob* pBlob = NULL, *pErrorBlob = NULL;
	ID3D11Device* pDevice = m_pDevice->GetDevice();

	if (SUCCEEDED(D3DX11CompileFromFile(L"../bin/Data/Fx/VertexColor.fx", NULL, NULL,
		"VS", "vs_4_0", swFlag, 0, NULL, &pBlob, &pErrorBlob, NULL)))
	{
		pDevice->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), NULL, &m_pVertexShader);
		pDevice->CreateInputLayout(
			tInputLayout, iElementNum, pBlob->GetBufferPointer(), pBlob->GetBufferSize(), &m_pVertexLayout);
	}
	else return E_FAIL;

	pBlob = pErrorBlob = NULL;
	if (SUCCEEDED(D3DX11CompileFromFile(L"../bin/Data/Fx/VertexColor.fx", NULL, NULL,
		"PS", "ps_4_0", swFlag, 0, NULL, &pBlob, &pErrorBlob, NULL)))
	{
		pDevice->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), NULL, &m_pPixelShader);
		::Safe_Release(pBlob);
	}
	else return E_FAIL;


	return S_OK;
}


void CColorShader::Update()
{

}

void CColorShader::Render()
{
	ID3D11DeviceContext* pDeviceContext = m_pDevice->GetDeviceCon();

	if (m_pVertexLayout)
		pDeviceContext->IASetInputLayout(m_pVertexLayout);
	if (m_pVertexShader)
		pDeviceContext->VSSetShader(m_pVertexShader, NULL, 0);
	if (m_pPixelShader)
		pDeviceContext->PSSetShader(m_pPixelShader, NULL, 0);
}

void CColorShader::Release()
{

}

