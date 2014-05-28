
#include "stdafx.h"
#include <windows.h>
#include "TreeListWnd.h"

__declspec(dllexport) BOOL __stdcall DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		OutputDebugString(TEXT("DLL_PROCESS_ATTACH\n"));
		TreeListRegister((HINSTANCE)hModule);
		break;
	case DLL_THREAD_ATTACH:
		OutputDebugString(TEXT("DLL_THREAD_ATTACH\n"));
		break;
	case DLL_THREAD_DETACH:
		OutputDebugString(TEXT("DLL_THREAD_DETACH\n"));
		break;
	case DLL_PROCESS_DETACH:
		OutputDebugString(TEXT("DLL_THREAD_DETACH\n"));
		TreeListUnregister((HINSTANCE)hModule);
		break;
	}
	return TRUE;
}
