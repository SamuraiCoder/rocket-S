#ifndef TIME_MANAGER
#define TIME_MANAGER

#include <iostream>
#include <assert.h>
#include "SDL.h"

/*
* Time Manager
* Class to manage time inside game as a last time that a screen was rendered.
* TODO: Also can create clocks and assign them to a callback. 
*/
namespace GameUtils
{
	class CTimeManager
	{
	public:
		static CTimeManager& Instance()
		{
			static CTimeManager _instance;
			return _instance;
		}

		void Update();
		void Pause() { state = GAME_STATE::PAUSE_STATE; };
		void Resume(){ state = GAME_STATE::PLAY_STATE; };
		float DeltaTime() { return deltaTime; }

	protected:
		CTimeManager();
		CTimeManager(const CTimeManager&);
		CTimeManager& operator=(const CTimeManager&);
		~CTimeManager(){ };
		
	private:
		//Last time we checked how many ticks we had since.
		uint64_t lastUpdate;
		//Last time that the last render was sent to screen.
		float deltaTime;
		//Enum that declares what is the current state 
		const enum GAME_STATE {
			PLAY_STATE = 0,
			PAUSE_STATE = 1,
		};
		GAME_STATE state;
	};

}

#endif