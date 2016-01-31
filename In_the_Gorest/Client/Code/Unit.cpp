#include "stdafx.h"
#include "Unit.h"

#include "Component.h"


CUnit::CUnit(CDevice* _pDevice)
: CObj(_pDevice)
{
	AddComponent();
}

CUnit::~CUnit()
{
}

void CUnit::AddComponent()
{
	// PhysicsInfo ------------
	m_pPhysicsInfo = dynamic_cast<CPhysicsInfo*>(CPhysicsInfo::Create(m_pDevice));
	NULL_CHECK(m_pPhysicsInfo);
	m_mapComponent.insert(make_pair(L"PhysicsInfo", m_pPhysicsInfo));

	// BoxCol ---------------
	m_pBoxCol = dynamic_cast<CBoxCol*>(CBoxCol::Create(m_pDevice));
	NULL_CHECK(m_pBoxCol);
	m_mapComponent.insert(make_pair(L"BoxCol", m_pBoxCol));
}

