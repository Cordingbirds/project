#include "stdafx.h"
#include "SceneMgr.h"

#include "Renderer.h"

#include "Loading.h"
#include "Title.h"
#include "Lobby.h"
#include "Room.h"
#include "InMap.h"

IMPLEMENT_SINGLETON(CSceneMgr)


CSceneMgr::CSceneMgr() :
m_pDevice(NULL),

m_pScene(NULL),
m_pRenderer(NULL)
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}

HRESULT CSceneMgr::SetScene(SceneID _eSceneID)
{
	if (m_pScene)
		::Safe_Delete(m_pScene);

	switch (_eSceneID)
	{
	case SCENE_ID_LODING:	m_pScene = CLoading::Create(m_pDevice); break;
	case SCENE_ID_TITLE:	m_pScene = CTitle::Create(m_pDevice);	break;
	case SCENE_ID_LOBBY:	m_pScene = CLobby::Create(m_pDevice);	break;
	case SCENE_ID_ROOM:		m_pScene = CRoom::Create(m_pDevice);	break;
	case SCENE_ID_INMAP:	m_pScene = CInMap::Create(m_pDevice);	break;
	default:				m_pScene = NULL;						break;
	}
	NULL_CHECK_RETURN(m_pScene, E_FAIL);
	FAILED_CHECK(m_pScene->Init());

	return S_OK;
}

HRESULT CSceneMgr::Init(ID3D11Device* _pDevice)
{
	m_pDevice = _pDevice;
	m_pRenderer = CRenderer::Create(CDevice::GetInstance());

	return S_OK;
}

void CSceneMgr::Update()
{
	if (m_pScene != NULL)
		m_pScene->Update_Layer();
}

void CSceneMgr::Render()
{
	if (m_pRenderer != NULL)
		m_pRenderer->Render();
}

void CSceneMgr::Release()
{
	Safe_Delete(m_pScene);
	Safe_Delete(m_pRenderer);
}
