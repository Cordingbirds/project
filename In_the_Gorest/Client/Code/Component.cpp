#include "stdafx.h"
#include "Component.h"

#include "Include.h"


CComponent::CComponent() :
m_pRefCnt(new WORD(0))
{

}

CComponent::~CComponent()
{

}

void CComponent::Release()
{
	Safe_Delete(m_pRefCnt);
}

