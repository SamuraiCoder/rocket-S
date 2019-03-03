#include "TimeManager.h"


namespace GameUtils
{
	CTimeManager* CTimeManager::_instance = 0;

	CTimeManager::CTimeManager()
	{
		assert(!_instance && "[CTimeManager] 2nd initialization of GraphicsManager!");
	}

	bool CTimeManager::Init()
	{
		_instance = new CTimeManager();
		
		if (_instance)
			return true;
		else
			return false;
	}

	void CTimeManager::Setup()
	{
		_instance->deltaTime = 0.0f;
		_instance->lastUpdate = 0;
		Resume();
	}

	CTimeManager::~CTimeManager()
	{
		if (_instance)
			delete _instance;
	}

	void CTimeManager::Update()
	{
		if (_instance->state == GAME_STATE::PAUSE_STATE)
		{
			_instance->deltaTime = 0;
		}
		else
		{
			Uint32 timeDifference = SDL_GetTicks() - _instance->lastUpdate;
			_instance->deltaTime = timeDifference / 1000.0f;
			_instance->lastUpdate = SDL_GetTicks();
		}
	}
}
