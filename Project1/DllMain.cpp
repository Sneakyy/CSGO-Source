#include "DllMain.h"
#include "SDK.h"
#include "Offsets.h"

bool StageEnd = false;

DWORD WINAPI Something(LPVOID hInstance)
{
	ExitThread(0);
}

DWORD WINAPI Stage1(LPVOID hInstance)
{
	surface = (ISurface*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("vguimatsurface.dll"), "CreateInterface"))		("VGUI_Surface031", nullptr));
	panel = (IVPanel*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("vgui2.dll"), "CreateInterface"))		("VGUI_Panel009", nullptr));
	client = (IBaseClientDLL*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("client_panorama.dll"), "CreateInterface"))		("VClient018", nullptr));
	entlist = (IClientEntityList*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("client_panorama.dll"), "CreateInterface"))		("VClientEntityList003", nullptr));
	engine = (IEngineClient*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("engine.dll"), "CreateInterface"))		("VEngineClient014", nullptr));

	clientmode = **(IClientMode***)((*(DWORD**)client)[10] + 0x5);
	globals = **(CGlobalVars***)((*(DWORD**)client)[0] + 0x1B);

	NetVarManager::DumpNetvars();
	Offsets::GetOffsets();

	ClientModeHook = std::make_unique<VMTHook>(clientmode);
	ClientModeHook->HookFunction(Hooks::hCreateMove, 24);

	ExitThread(0);
}

BOOL WINAPI CreateThreads(HINSTANCE hInstance)
{
	return CreateThread(nullptr, 0, Stage1, hInstance, 0, nullptr) && CreateThread(nullptr, 0, Something, hInstance, 0, nullptr);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	Timer = clock();
	if (fdwReason == 1 && FindWindow("Valve001", 0)) {
		return CreateThreads(hinstDLL);
	}
}