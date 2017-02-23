#include "stdafx.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPTSTR    lpCmdLine,
		int       nCmdShow)
{
		XInitXCGUI();
		srand(time(NULL));
		Welcome iw;
		iw.Initialize();
		XRunXCGUI();
		return 0;
}

