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


// D3DX -----------------------------
#include <D3DX11.h>
#pragma  comment(lib, "d3dx11.lib")
#include <D3D11.h>
#pragma  comment(lib, "d3d11.lib")
#include <D3DX9.h>
#pragma  comment(lib, "d3dx9.lib")
#include <D3D9.h>
#pragma  comment(lib, "d3d9.lib")


// Debuging -----------------------------
#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#endif

#include <crtdbg.h>


// Waring -----------------------------
#pragma warning(disable : 4244) 
#pragma warning(disable : 4800)
#pragma warning(disable : 4005)


// Mgr ----------------------------------
#include "Device.h"
#include "Timer.h"