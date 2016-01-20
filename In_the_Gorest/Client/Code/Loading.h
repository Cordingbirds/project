#pragma once
#include "Scene.h"

class CLoading : public CScene
{
public :
	static CLoading*	Create(ID3D11Device*);

public:
	virtual HRESULT		Init();
	virtual void		Update();
	virtual void		Render();
	virtual void		Release();

private:
	explicit CLoading(ID3D11Device*);
public :
	virtual ~CLoading();
};

