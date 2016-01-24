#pragma once
#include "Scene.h"

class CDevice;
class CInMap : public CScene
{
public:
	static CInMap*	Create(CDevice*);

public:
	virtual HRESULT		Init();
	virtual void		Update();
	virtual void		Render();
	virtual void		Release();

private:
	explicit CInMap(CDevice*);
public:
	virtual ~CInMap();
};

