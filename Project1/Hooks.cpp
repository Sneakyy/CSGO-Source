#include "Hooks.h"
#include "Misc.h"

namespace Hooks
{
	bool __stdcall hCreateMove(float frametime, CUserCmd* cmd)
	{
		ClientModeHook->GetOriginalFunction<CreateMoveFn>(24)(clientmode, frametime, cmd);
		if (cmd && cmd->command_number)
		{
			Misc::CreateMove(cmd);
//			AutoStrafe::CreateMove(cmd);
		}
		else
			return ClientModeHook->GetOriginalFunction<CreateMoveFn>(24)(clientmode, frametime, cmd);

		return false;
	}
}