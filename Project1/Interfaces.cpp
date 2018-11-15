#include "Interfaces.h"

IBaseClientDLL* client;
IEngineClient* engine;
IClientEntityList* entlist;
IClientMode* clientmode;
ISurface* surface;
IVPanel* panel;
CGlobalVars* globals;

std::unique_ptr<VMTHook>ClientModeHook;