#pragma once
//Basic Includes
#include "Functions.h"
#include "Vector.h"
#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>
#include "Color.h"
#include "FindPattern.h"
#include "Definitions.h"

struct CUserCmd
{
	virtual ~CUserCmd() {};
	int command_number;
	int tick_count;
	Vector viewangles;
	Vector aimdirection;
	float forwardmove;
	float sidemove;
	float upmove;
	int buttons;
	unsigned char impulse;
	int weaponselect;
	int weaponsubtype;
	int random_seed;
	short mousedx;
	short mousedy;
	bool hasbeenpredicted;
	Vector headangles;
	Vector headoffset;
};

//Interface Includes
#include "Offsets.h"
#include "VMTHook.h"
#include "Hooks.h"
#include "IVPanel.h"
#include "ISurface.h"
#include "CGlobalVars.h"
#include "IBaseClientDLL.h"
#include "IEngineClient.h"
#include "IClientEntity.h"
#include "IClientEntityList.h"
#include "IClientMode.h"
#include "NetvarManager.h"
#include "Interfaces.h"
#include "IInputSystem.h"
#include "Strafer.h"

typedef void* (*CreateInterfaceFn) (const char*, int*);
