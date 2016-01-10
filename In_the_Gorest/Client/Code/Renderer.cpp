#include "stdafx.h"
#include "Renderer.h"

#include "Device.h"

CRenderer::CRenderer(CDevice* _pDevice) :
m_pDeviceClass(_pDevice),
m_pScene(NULL)
{

}

CRenderer::~CRenderer(void)
{

}

CRenderer* CRenderer::Create(CDevice* _pDeviceClass)
{
	CRenderer* pRenderer = new CRenderer(_pDeviceClass);

	if (FAILED(pRenderer->Init()))
		Safe_Delete(pRenderer);


	return pRenderer;
}

HRESULT CRenderer::Init()
{
	return S_OK;
}

void CRenderer::Render()
{
	m_pDeviceClass->Render_Begin();

	if (m_pScene != NULL)
		m_pScene->Render();
	
	m_pDeviceClass->Render_End();
}



