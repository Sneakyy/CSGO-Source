#pragma once
#include <Windows.h>
#include "SDK.h"

typedef bool(__thiscall* CreateMoveFn)(IClientMode*, float, CUserCmd*);

namespace Hooks
{
	bool __stdcall hCreateMove(float frametime, CUserCmd* cmd);
}