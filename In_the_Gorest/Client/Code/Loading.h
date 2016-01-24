#pragma once
#include "Scene.h"


class CDevice;
class CLoading : public CScene
{
public :
	static CLoading*	Create(CDevice*);

public:
	virtual HRESULT		Init();
	virtual void		Update();
	virtual void		Render();
	virtual void		Release();

private:
	explicit CLoading(CDevice*);
public :
	virtual ~CLoading();
};

