#pragma once

#include <Windows.h>
#include <assert.h>

class CWindowManager
{
public:
	static CWindowManager *m_pInstance;
	static CWindowManager& Get() { assert(m_pInstance); return *m_pInstance; }

public:
	CWindowManager();
	~CWindowManager();

	bool Create(HINSTANCE hInst);
	void Destroy();

	HWND GetHWND() { return hWnd; }

private:
	HWND hWnd;
};