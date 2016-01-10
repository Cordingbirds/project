#pragma once
#include "Scene.h"


class CTitle : public CScene
{
public:
	static CTitle*	Create(ID3D11Device*);

public:
	virtual HRESULT		Init();
	virtual void		Update();
	virtual void		Render();
	virtual void		Release();

private:
	explicit CTitle(ID3D11Device*);
public:
	virtual ~CTitle();
};

