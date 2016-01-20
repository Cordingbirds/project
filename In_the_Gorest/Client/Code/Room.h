#pragma once
#include "Scene.h"
class CRoom : public CScene
{
public:
	static CRoom*	Create(ID3D11Device*);

public:
	virtual HRESULT		Init();
	virtual void		Update();
	virtual void		Render();
	virtual void		Release();

private:
	explicit CRoom(ID3D11Device*);
public:
	virtual ~CRoom();
};

