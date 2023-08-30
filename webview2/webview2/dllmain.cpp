// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

DWORD WINAPI msgcl(LPVOID p) {
	MSG msg;
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// Other program lines to do some work
		}
		//Sleep(10);
	}
	return -1;
}

DWORD threadId;
HANDLE hThread = CreateThread(NULL, 0, msgcl, 0, 0, &threadId);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

