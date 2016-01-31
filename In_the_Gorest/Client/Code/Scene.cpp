#include "stdafx.h"
#include "Scene.h"

#include "Function.h"


CScene::CScene(CDevice* _pDevice)
: m_pDevice(_pDevice)
{
	for (int i = 0; i < CLayer::LAYERTYPE_END; ++i)
		m_pLayer[i] = NULL;
}


CScene::~CScene()
{
	ReleaseLayer();
}

void CScene::Update_Layer()
{
	for (int i = 0; i < CLayer::LAYERTYPE_END; ++i)
	{
		if (NULL != m_pLayer[i] )
			m_pLayer[i]->Update_Obj();
	}
}

void CScene::Render_Layer()
{
	for (int i = 0; i < CLayer::LAYERTYPE_END; ++i)
	{
		if (NULL != m_pLayer[i])
			m_pLayer[i]->Render_Obj();
	}
}

void CScene::ReleaseLayer()
{
	for (int i = 0; i < CLayer::LAYERTYPE_END; ++i)
		::Safe_Delete(m_pLayer[i]);
}
