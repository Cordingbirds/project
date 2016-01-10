#pragma once
#include "Scene.h"
class CInMap : public CScene
{
public:
	static CInMap*	Create(ID3D11Device*);

public:
	virtual HRESULT		Init();
	virtual void		Update();
	virtual void		Render();
	virtual void		Release();

private:
	explicit CInMap(ID3D11Device*);
public:
	virtual ~CInMap();
};

