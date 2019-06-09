#include "TimeManager.h"

using std::cout;
using std::endl;

namespace GameUtils
{
	CTimeManager::CTimeManager()
	{
		cout << "[TimeManager] CTimeManager init" << endl;
		deltaTime = 0.0f;
		lastUpdate = 0;
		state = GAME_STATE::PLAY_STATE;
	}

	void CTimeManager::Update()
	{
		if (state == GAME_STATE::PAUSE_STATE)
		{
			deltaTime = 0;
		}
		else
		{
			uint64_t timeDifference = SDL_GetTicks() - lastUpdate;
			deltaTime = timeDifference / 1000.0f;
			lastUpdate = SDL_GetTicks();
		}
	}
}
