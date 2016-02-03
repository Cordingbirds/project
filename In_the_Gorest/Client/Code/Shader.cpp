#include "stdafx.h"
#include "Shader.h"

CShader::CShader(CDevice* _pDevice)
: m_pDevice(_pDevice)
, m_pVertexShader(NULL)
, m_pVertexLayout(NULL)

, m_pPixelShader(NULL)
{

}

CShader::~CShader()
{

}