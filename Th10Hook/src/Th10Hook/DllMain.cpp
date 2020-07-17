#include "Th10Hook/Common.h"
#include "Th10Hook/DllMain.h"

#include "Th10Hook/DllLoader.h"

HMODULE g_dll = nullptr;

BOOL APIENTRY DllMain(HMODULE module, DWORD reasonForCall, LPVOID reserved)
{
	switch (reasonForCall)
	{
	case DLL_PROCESS_ATTACH:
	{
		g_dll = module;
		th::DllLoader& dllLoader = th::DllLoader::GetInstance();
		dllLoader.start();
		break;
	}

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}