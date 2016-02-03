#pragma once

#include "Include.h"


class CDevice
{
	DECLARE_SINGLETON(CDevice)

public :
	enum WinMode { WIN_MODE_FULL, WIN_MODE_WIN };

private :
	static const float COLOR_BACKBUFFER[4];

private :
	ID3D11Device*			m_pDevice;
	ID3D11DeviceContext*	m_pDeviceContext;

	IDXGISwapChain*			m_pSwapChain;
	ID3D11RenderTargetView* m_pRenderTargetView;
	ID3D11Texture2D*		m_pDepthStencilBuffer;
	ID3D11DepthStencilView* m_pDepthStencilView;

	//D3D11_VIEWPORT			m_tScreenViewport;

	
public:
	HRESULT		Init(WinMode _eWinMode = WIN_MODE_WIN);
	void		Release();

	void		Render_Begin(void);
	void		Render_End(void);


public :
	ID3D11Device*			GetDevice()					{ return m_pDevice; }
	ID3D11DeviceContext*	GetDeviceContext()			{ return m_pDeviceContext; }

	IDXGISwapChain*			GetSwapChain()				{ return m_pSwapChain; }
	ID3D11RenderTargetView*	GetRenderTargetView()		{ return m_pRenderTargetView; }
	ID3D11Texture2D*		GetSDepthStencilBuffer()	{ return m_pDepthStencilBuffer; }
	ID3D11DepthStencilView*	GetDepthStencilView()		{ return m_pDepthStencilView; }


private :
	explicit CDevice();
	~CDevice();
};

