#include "stdafx.h"
#include "Scene.h"

#include "Include.h"
#include "Layer.h"


CScene::CScene(ID3D11Device* _pDevice) :
m_pDevice(_pDevice)
{
}


CScene::~CScene()
{
	ReleaseLayer();
}

void CScene::Update_Layer()
{
	map<WORD, CLayer*>::iterator	iter = m_mapLayer.begin();
	map<WORD, CLayer*>::iterator	iter_end = m_mapLayer.end();

	for (; iter != iter_end; ++iter)
		iter->second->Update_Obj();
}

void CScene::Render_Layer()
{
	map<WORD, CLayer*>::iterator	iter = m_mapLayer.begin();
	map<WORD, CLayer*>::iterator	iter_end = m_mapLayer.end();

	for (; iter != iter_end; ++iter)
		iter->second->Render_Obj();
}

void CScene::ReleaseLayer()
{
	for_each(m_mapLayer.begin(), m_mapLayer.end(), DeleteMap());
	m_mapLayer.clear();
}
