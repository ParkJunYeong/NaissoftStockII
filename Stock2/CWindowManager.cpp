#include "CWindowManager.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

CWindowManager::CWindowManager()
{
}

CWindowManager::~CWindowManager()
{
}

bool CWindowManager::Create(HINSTANCE hInst)
{
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("Stock2Window");
	wc.lpszMenuName = 0;
	wc.style = 0;
	RegisterClass(&wc);

	hWnd = CreateWindow(TEXT("Stock2Window"), TEXT("Stock2 - 주식 게임 2"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		0, 0, hInst, 0);
	ShowWindow(hWnd, SW_NORMAL);

	return true;
}

void CWindowManager::Destroy()
{
	DestroyWindow(hWnd);
}
