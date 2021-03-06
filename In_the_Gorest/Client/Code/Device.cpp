#include "stdafx.h"
#include "Device.h"

extern HWND		g_hWnd;

IMPLEMENT_SINGLETON(CDevice)

const float CDevice::COLOR_BACKBUFFER[4] = { 0.f, 0.f, 0.f, 0.f };


CDevice::CDevice()
: m_pDevice(NULL)
, m_pDeviceContext(NULL)

, m_pSwapChain(NULL)
, m_pRenderTargetView(NULL)
, m_pDepthStencilBuffer(NULL)
, m_pDepthStencilView(NULL)
{
}


CDevice::~CDevice()
{
	Release();
}

HRESULT CDevice::Init(WinMode _eWinMode)
{
	UINT	deviceFlags = 0;
#if defined(DEBUG) || defined(_DEBUG)
	deviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif


	D3D_FEATURE_LEVEL	featureLEvel;
	FAILED_CHECK(D3D11CreateDevice(0, D3D_DRIVER_TYPE_HARDWARE,
		0, deviceFlags, 0, 0, D3D11_SDK_VERSION,
		&m_pDevice, &featureLEvel, &m_pDeviceContext));

	if (featureLEvel != D3D_FEATURE_LEVEL_11_0)
	{
		MSG_BOX(_T("Direct3D Feature Level 11 unsupported."));
		return S_FALSE;
	}


	UINT      msaaQuality;
	FAILED_CHECK(m_pDevice->CheckMultisampleQualityLevels(
		DXGI_FORMAT_R8G8B8A8_UINT, 4, &msaaQuality));


	DXGI_SWAP_CHAIN_DESC swapChain;
	swapChain.BufferDesc.Width = (UINT)CLIENT_WINCX;
	swapChain.BufferDesc.Height = (UINT)CLIENT_WINCY;

	swapChain.BufferDesc.RefreshRate.Numerator = 60;
	swapChain.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChain.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChain.BufferDesc.RefreshRate.Denominator = 1;
	swapChain.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	swapChain.SampleDesc.Count = 1;
	swapChain.SampleDesc.Quality = 0;

	swapChain.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChain.BufferCount = 1;
	swapChain.OutputWindow = g_hWnd;
	swapChain.Windowed = _eWinMode;
	swapChain.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChain.Flags = 0;


	IDXGIDevice* dxgiDevice = 0;
	FAILED_CHECK(m_pDevice->QueryInterface(
		__uuidof(IDXGIDevice), (void**)&dxgiDevice));


	IDXGIAdapter* dxgiAdapter = 0;
	FAILED_CHECK(dxgiDevice->GetParent(
		__uuidof(IDXGIAdapter), (void**)&dxgiAdapter));


	IDXGIFactory* dxgiFactory = 0;
	FAILED_CHECK(dxgiAdapter->GetParent(
		__uuidof(IDXGIFactory), (void**)&dxgiFactory));


	FAILED_CHECK(dxgiFactory->CreateSwapChain(m_pDevice, &swapChain, &m_pSwapChain));


	::Safe_Release(dxgiDevice);
	::Safe_Release(dxgiAdapter);
	::Safe_Release(dxgiFactory);


	FAILED_CHECK(m_pSwapChain->ResizeBuffers(
		1, (UINT)CLIENT_WINCX, (UINT)CLIENT_WINCY, DXGI_FORMAT_R8G8B8A8_UNORM, 0));


	ID3D11Texture2D* backBuffer;
	FAILED_CHECK(m_pSwapChain->GetBuffer(
		0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer)));

	FAILED_CHECK(m_pDevice->CreateRenderTargetView(backBuffer, 0, &m_pRenderTargetView));


	::Safe_Release(backBuffer);


	D3D11_TEXTURE2D_DESC depthStencil;

	depthStencil.Width = (UINT)CLIENT_WINCX;
	depthStencil.Height = (UINT)CLIENT_WINCY;
	depthStencil.MipLevels = 1;
	depthStencil.ArraySize = 1;
	depthStencil.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;

	depthStencil.SampleDesc.Count = 1;
	depthStencil.SampleDesc.Quality = 0;

	depthStencil.Usage = D3D11_USAGE_DEFAULT;
	depthStencil.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthStencil.CPUAccessFlags = 0;
	depthStencil.MiscFlags = 0;


	FAILED_CHECK(m_pDevice->CreateTexture2D(
		&depthStencil, 0, &m_pDepthStencilBuffer));

	FAILED_CHECK(m_pDevice->CreateDepthStencilView(
		m_pDepthStencilBuffer, 0, &m_pDepthStencilView));


	m_pDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, m_pDepthStencilView);


	D3D11_VIEWPORT screenViewport;
	screenViewport.TopLeftX = 0;
	screenViewport.TopLeftY = 0;
	screenViewport.Width = CLIENT_WINCX;
	screenViewport.Height = CLIENT_WINCY;
	screenViewport.MinDepth = 0.f;
	screenViewport.MaxDepth = 1.f;

	m_pDeviceContext->RSSetViewports(1, &screenViewport);


	return S_OK;
}

void CDevice::Release()
{
	::Safe_Release(m_pDepthStencilView);
	::Safe_Release(m_pDepthStencilBuffer);
	::Safe_Release(m_pRenderTargetView);
	::Safe_Release(m_pSwapChain);

	if (m_pDeviceContext)
		::Safe_Release(m_pDeviceContext);

	::Safe_Release(m_pDeviceContext);
	::Safe_Release(m_pDevice);
}

void CDevice::Render_Begin(void)
{
	m_pDeviceContext->ClearRenderTargetView(m_pRenderTargetView, COLOR_BACKBUFFER);
	m_pDeviceContext->ClearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.f, 0);
}

void CDevice::Render_End(void)
{
	FAILED(m_pSwapChain->Present(0, 0));
}
