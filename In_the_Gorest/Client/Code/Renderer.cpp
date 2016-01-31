#include "stdafx.h"
#include "Renderer.h"

#include "Device.h"
#include "ColorShader.h"

CRenderer::CRenderer(CDevice* _pDevice)
: m_pDevice(_pDevice)
, m_pScene(NULL)
, m_pColorShader(NULL)
{

}

CRenderer::~CRenderer(void)
{

}

CRenderer* CRenderer::Create(CDevice* _pDeviceClass)
{
	CRenderer* pRenderer = new CRenderer(_pDeviceClass);

	if (FAILED(pRenderer->Init()))
		::Safe_Delete(pRenderer);


	return pRenderer;
}

HRESULT CRenderer::Init()
{
	m_pColorShader = dynamic_cast<CColorShader*>(CColorShader::Create(m_pDevice));

	return S_OK;
}

void CRenderer::Render()
{
	m_pDevice->Render_Begin();


	m_pColorShader->Render();

	if (m_pScene != NULL)
		m_pScene->Render();
	
	m_pDevice->Render_End();
}



