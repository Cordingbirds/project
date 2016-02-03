#include "stdafx.h"
#include "Rider.h"

#include "Component.h"


CRider::CRider(CDevice* _pDevice)
: CUnit(_pDevice)
{
	AddComponent();
}

CRider::~CRider()
{

}

void CRider::AddComponent()
{
	// UserInfo ------------
	m_pUserInfo = dynamic_cast<CUserInfo*>(CUserInfo::Create());
	NULL_CHECK(m_pUserInfo);
	m_mapComponent.insert(make_pair(L"UserInfo", m_pUserInfo));

	// PlayingInfo ---------------
	m_pPlayingInfo = dynamic_cast<CPlayingInfo*>(CPlayingInfo::Create());
	NULL_CHECK(m_pPlayingInfo);
	m_mapComponent.insert(make_pair(L"PlayingInfo", m_pPlayingInfo));

	// RecosterInfo ---------------
	m_pRecosterInfo = dynamic_cast<CRecosterInfo*>(CRecosterInfo::Create());
	NULL_CHECK(m_pRecosterInfo);
	m_mapComponent.insert(make_pair(L"RecosterInfo", m_pRecosterInfo));
}

