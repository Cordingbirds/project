#include "stdafx.h"
#include "PlayingInfo.h"

CPlayingInfo::CPlayingInfo()
: m_eInMapState(INMAP_STATE_NONE)
, m_eAniState(ANI_STATE_NONE)

, m_wGradeNum(0)
, m_wRabNum(0)
, m_fProgressRate(0.f)

, m_wHP(MAX_HP)
{

}

CPlayingInfo::~CPlayingInfo()
{
	Release();
}

CComponent* CPlayingInfo::Create()
{
	return new CPlayingInfo;
}

void CPlayingInfo::Update()
{

}

void CPlayingInfo::Release()
{
}
