#ifndef _BASEWINDOW_H
#define _BASEWINDOW_H

#include <Windows.h>
#include "main.h"

class BaseWindow
{
	protected:
		HWND m_hwnd;
		HDC m_hDC, m_hDCmem;
		int m_width, m_height;
		PBYTE* ScanLine;

	public:
		BaseWindow() {
			m_hwnd = NULL;
			m_hDC = m_hDCmem = NULL;
			m_width = m_height = 0; 
		}
		
		virtual ~BaseWindow() {};

		BOOL Create(LPCTSTR lpszClass, LPCTSTR lpszName, DWORD dwstyle,
		int x, int y, int nWidth, int nHeight, HWND hParent, HMENU hMenu, HINSTANCE hInstance);
		BOOL Create(int nWidth, int nHeight, HINSTANCE hInstance);
		BOOL Create(HINSTANCE hInstance);
		
		HBITMAP CreateDIB();
		WPARAM MsgLoop(void);

		void Render();
		void Render_base();
};

#endif