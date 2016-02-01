#include "stdafx.h"
#include "InMap.h"

#include "Layer.h"
#include "ResourceMgr.h"

#include "Player.h"
#include "DynamicCamera.h"


CInMap::CInMap(CDevice* _pDevice)
: CScene(_pDevice)
{
}


CInMap::~CInMap()
{
	Release();
}

CInMap* CInMap::Create(CDevice* _pDevice)
{
	CInMap* pScene = new CInMap(_pDevice);

	if (FAILED(pScene->Init()))
		::Safe_Delete(pScene);

	return pScene;
}

HRESULT CInMap::Init()
{
	// (수정) LoadMgr에 넣어주자.
	CResourceMgr::GetInstance()->AddBuffer(m_pDevice,
		CResourceMgr::BUFFER_TYPE_CUBE, CResourceMgr::RESOURCE_TYPE_DYNAMIC, L"CubeColor");

	FAILED_CHECK(AddLayer_Environment());
	FAILED_CHECK(AddLayer_GameLogic());
	FAILED_CHECK(AddLayer_UI());

	return S_OK;
}

void CInMap::Update()
{
	CScene::Update_Layer();
}

void CInMap::Render()
{
	CScene::Render_Layer();
}

void CInMap::Release()
{

}

HRESULT CInMap::AddLayer_Environment()
{
	CLayer*		pLayer = CLayer::Create(m_pDevice);
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	m_pLayer[CLayer::LAYERTYPE_ENVIRONMENT] = pLayer;

	return S_OK;
}

HRESULT CInMap::AddLayer_GameLogic()
{
	CLayer*		pLayer = CLayer::Create(m_pDevice);
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	CObj* pObj = NULL;
	
	// Player
	pObj = CPlayer::Create(m_pDevice);
	NULL_CHECK_RETURN(pObj, E_FAIL);
	pLayer->AddObj(L"Player", pObj);

	m_pLayer[CLayer::LAYERTYPE_GAMELOGIC] = pLayer;

	return S_OK;
}

HRESULT CInMap::AddLayer_UI()
{
	CLayer*		pLayer = CLayer::Create(m_pDevice);
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	CObj* pObj = NULL;

	// Camera
	pObj = CDynamicCamera::Create(m_pDevice);
	NULL_CHECK_RETURN(pObj, E_FAIL);
	((CDynamicCamera*)pObj)->SetPos(D3DXVECTOR3(0.f, 1.f, -10.f));
	pLayer->AddObj(L"DynamicCamera", pObj);

	m_pLayer[CLayer::LAYERTYPE_UI] = pLayer;

	return S_OK;
}
