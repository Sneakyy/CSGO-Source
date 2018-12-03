#include "Misc.h"

float AngleNormalize(float angle)
{
    angle = fmodf(angle, 360.0f);
    if (angle > 180)
    {
        angle -= 360;
    }
    if (angle < -180)
    {
        angle += 360;
    }
    return angle;
}

void Misc::CreateMove(CUserCmd *cmd)
{
	C_BasePlayer* localplayer = (C_BasePlayer*)entlist->GetClientEntity(engine->GetLocalPlayer());

	if (localplayer->GetFlags() & FL_ONGROUND)
	{
		if (cmd->mousedx != 0) 
		{
			if (g_LocalPlayer->m_vecVelocity().Length2D() > 280) 
			{
				static AutoStrafer Strafer;
				double yawrad = AngleNormalize(cmd->viewangles.yaw) * PI / 180;
				double tau = g_GlobalVars->interval_per_tick, MA = 320 * 100;
				int Sdir = 0, Fdir = 0;
				Vector velocity = g_LocalPlayer->m_vecVelocity();
				double vel[3] = { velocity[0], velocity[1], velocity[2] };
				double pos[2] = { 0, 0 };
				int dir = 0;
				if (cmd->mousedx > 0)
					dir = 1;
				else if (cmd->mousedx < 0)
					dir = -1;
				Strafer.strafe_side_opt(yawrad, Sdir, Fdir, vel, 30.0, tau * MA, dir);
				cmd->viewangles.yaw = AngleNormalize(yawrad * 180 / PI);

				g_EngineClient->SetViewAngles(cmd->viewangles);
			}
		}
	}
}
