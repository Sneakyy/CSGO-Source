#include "Misc.h"

void Misc::CreateMove(CUserCmd *cmd)
{
	C_BasePlayer* localplayer = (C_BasePlayer*)entlist->GetClientEntity(engine->GetLocalPlayer());

	if (localplayer->GetFlags() & FL_ONGROUND)
	{
		engine->ClientCmd_Unrestricted("echo derp");
	}
}