#include <stdafx.h>

static void OnTick()
{
	static auto lastTick = GetTickCount64();
	auto curTick = GetTickCount64();

	if (lastTick < curTick - 100)
	{
		lastTick = curTick;

		for (auto veh : GetAllVehs())
		{
			if (!IS_ENTITY_IN_AIR(veh))
			{
				APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(veh, 0, .0f, .0f, 200.f, true, false, true, true);
			}
		}
	}
}

static RegisterEffect registerEffect(EFFECT_JUMPY_VEHS, nullptr, nullptr, OnTick);