// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

// STL -----------------------------
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <functional>

using namespace  std;


// Etc -------------------------------
#include <time.h>


// D3DX -----------------------------
#include <D3DX11.h>
#include <D3D11.h>

#include <D3DX10.h>
#include <D3D10.h>

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>


#pragma  comment(lib, "d3dx11.lib")
#pragma  comment(lib, "d3d11.lib")

#pragma  comment(lib, "d3dx10.lib")
#pragma  comment(lib, "d3d10.lib")

#pragma  comment(lib, "D3DCompiler.lib")
#pragma  comment(lib, "dxerr.lib")
#pragma  comment(lib, "dxgi.lib")

#pragma  comment(lib, "dinput8.lib")
#pragma  comment(lib, "dxguid.lib")

#ifdef _DEBUG
	#pragma  comment(lib, "d3dx11d.lib")
	#pragma  comment(lib, "Effects11d.lib")
#else
	#pragma  comment(lib, "d3dx11.lib")
	#pragma  comment(lib, "Effects11.lib")
#endif


// Debuging -----------------------------
#ifdef _DEBUG
	#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#endif

#include <crtdbg.h>


// Waring -----------------------------
//#pragma warning(disable : 4244) 
//#pragma warning(disable : 4800)


// Mgr ----------------------------------
#include "Device.h"
#include "Timer.h"
