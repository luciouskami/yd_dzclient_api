#include "framework.h"
#include "dll_module.h"
#include "dz_w3_plugin.h"
#include <fstream>


extern unsigned char dz_w3_plugin_shellcode[];

dll_module::dll_module()
	:dz_w3_plugin_handle(0)
	, game_module_handle(0)
	, storm_module_handle(0)
{}


dll_module::~dll_module()
{
}

void dll_module::attach()
{
	this->export_dz_w3_plugin();
}

void dll_module::detach()
{
}

auto dll_module::export_dz_w3_plugin() -> bool
{
	using std::ios;
	using std::fstream;
	fstream v_temp_dz_w3_plugin_file;

	try
	{
		//ios::noreplace 
		v_temp_dz_w3_plugin_file.open("dz_w3_plugin.dll", ios::binary | ios::out);
		if (v_temp_dz_w3_plugin_file.is_open())
		{
			v_temp_dz_w3_plugin_file.write(reinterpret_cast<const char*>(dz_w3_plugin_shellcode),
			                               sizeof(dz_w3_plugin_shellcode));
			v_temp_dz_w3_plugin_file.close();
			dz_w3_plugin_handle = reinterpret_cast<uintptr_t>(LoadLibraryW(L"dz_w3_plugin.dll"));
			return NULL != dz_w3_plugin_handle;
		}
	}
	catch (...)
	{
		return false;
	}
	return false;
}

