#pragma once
#include "Scene.h"
class CLobby : public CScene
{
public:
	static CLobby*	Create(ID3D11Device*);

public:
	virtual HRESULT		Init();
	virtual void		Update();
	virtual void		Render();
	virtual void		Release();

private:
	explicit CLobby(ID3D11Device*);
public:
	virtual ~CLobby();
};

