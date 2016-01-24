#include "stdafx.h"
#include "RecosterInfo.h"

CRecosterInfo::CRecosterInfo()
: m_wRecoterNum(0)
, m_wRecoterGauge(0)
{
}

CRecosterInfo::~CRecosterInfo()
{
	Release();
}

CComponent* CRecosterInfo::Create()
{
	return new CRecosterInfo;
}

void CRecosterInfo::Update()
{

}

void CRecosterInfo::Release()
{
}
