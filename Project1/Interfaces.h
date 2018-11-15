#pragma once
#include "SDK.h"

extern IBaseClientDLL* client;
extern ISurface* surface;
extern IVPanel* panel;
extern IEngineClient* engine;
extern IClientEntityList* entlist;
extern IClientMode* clientmode;
extern CGlobalVars* globals;

extern std::unique_ptr<VMTHook>ClientModeHook;