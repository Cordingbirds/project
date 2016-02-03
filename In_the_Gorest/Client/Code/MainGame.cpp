#include "stdafx.h"
#include "MainGame.h"

#include <time.h>
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include <conio.h>

extern HINSTANCE g_hInst;
extern HWND g_hWnd;

CMainGame::CMainGame()
{

}

CMainGame::~CMainGame()
{
	Release();
}

HRESULT CMainGame::Init()
{
	srand(unsigned int(time(NULL)));

	FAILED_CHECK(CDevice::GetInstance()->Init(CDevice::WIN_MODE_WIN));
	m_pDevice = CDevice::GetInstance();
	NULL_CHECK_RETURN(m_pDevice, E_FAIL);

	// Mgr ---------------------
	m_pSceneMgr = CSceneMgr::GetInstance();
	m_pTimer = CTimer::GetInstance();
	m_pKeyMgr = CKeyMgr::GetInstance();


	// Mgr Init ----------------
	m_pSceneMgr->Init(m_pDevice);
	m_pSceneMgr->SetScene(CSceneMgr::SCENE_ID_INMAP);
	m_pTimer->InitTime();
	m_pKeyMgr->Init(g_hInst, g_hWnd);


	return S_OK;
}
							
void CMainGame::Update()
{
	m_pTimer->UpdateTime();
	m_pKeyMgr->UpdateInputState();
	m_pSceneMgr->Update();
}

void CMainGame::Render()
{
	m_pSceneMgr->Render();
}

void CMainGame::Release()
{
	m_pTimer->DestroyInstance();
	m_pKeyMgr->DestroyInstance();
	m_pSceneMgr->DestroyInstance();

	CObjMgr::GetInstance()->DestroyInstance();

	m_pDevice->DestroyInstance();
}
