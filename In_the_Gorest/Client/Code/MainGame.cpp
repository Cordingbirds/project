#include "stdafx.h"
#include "MainGame.h"

#include <time.h>
#include "Device.h"
#include "SceneMgr.h"


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

	FAILED_CHECK(CDevice::GetInstance()->InitDevice(CDevice::WIN_MODE_WIN));
	m_pDevice = CDevice::GetInstance()->GetDevice();
	NULL_CHECK_RETURN(m_pDevice, E_FAIL);

	CTimer::GetInstance()->InitTime();

	CSceneMgr::GetInstance()->Init(m_pDevice);
	CSceneMgr::GetInstance()->SetScene(CSceneMgr::SCENE_ID_LODING);


	return S_OK;
}
							
void CMainGame::Update()
{
	CTimer::GetInstance()->SetTime();
	CSceneMgr::GetInstance()->Update();
}

void CMainGame::Render()
{
	CSceneMgr::GetInstance()->Render();
}

void CMainGame::Release()
{
	CTimer::GetInstance()->DestroyInstance();
	CSceneMgr::GetInstance()->DestroyInstance();

	CDevice::GetInstance()->DestroyInstance();
}
