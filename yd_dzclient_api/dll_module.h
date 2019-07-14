#pragma once
class dll_module
{
public:
	dll_module();
	~dll_module();
	void attach();
	void detach();
	//ÊÍ·Å²å¼þ
	bool export_dz_w3_plugin();
public:
	uintptr_t dz_w3_plugin_handle;
	uintptr_t game_module_handle;
	uintptr_t storm_module_handle;
private:
	

};
extern dll_module g_DMod;