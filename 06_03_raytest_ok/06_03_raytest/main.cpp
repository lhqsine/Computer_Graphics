#include "main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	BaseWindow win;

	win.Create(480, 480, hInstance);
	win.MsgLoop();

	return 0;
}