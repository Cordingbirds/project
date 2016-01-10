#pragma once

#include "Include.h"

class CDevice;
class CMainGame
{
private :
	ID3D11Device*	m_pDevice;


public :
	static CMainGame*	Create();

public :
	HRESULT		Init();
	void		Update();
	void		Render();
	void		Release();

public:
	CMainGame();
	~CMainGame();
};

