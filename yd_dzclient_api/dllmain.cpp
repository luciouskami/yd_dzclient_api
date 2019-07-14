// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "framework.h"
#include "dll_module.h"

dll_module g_DMod;
bool g_lock = false;

//初始化函数
void Initialize()
{
	if (!g_lock)
	{
		g_DMod.attach();
		g_lock = true;
	}
	

}

BOOL APIENTRY DllMain( HMODULE hModule,
					   DWORD  ul_reason_for_call,
					   LPVOID /*lpReserved*/
					 )
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
	}
	else if(ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		if (g_lock)
		{
			g_DMod.detach();
			g_lock = false;
		}
		
	}

	return TRUE;
}

