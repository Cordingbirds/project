#pragma once
#include "Scene.h"

class CDevice;
class CInMap : public CScene
{
public:
	static CInMap*	Create(CDevice*);

private :
	HRESULT		AddLayer_Environment();
	HRESULT		AddLayer_GameLogic();
	HRESULT		AddLayer_UI();


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

