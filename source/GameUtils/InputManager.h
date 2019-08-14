#ifndef INPUT_MANAGER
#define INPUT_MANAGER

#include "Globals.h"

#include <iostream>
#include <assert.h>
#include <SDL.h>
#include <list>

namespace GameUtils
{
	/*
	* This class must be implemented for all the clases that want
	* to register into the peripherical system
	* Functions will return if key is being pressed.
	* (by default will be false)
	*/
	class CKeyboardListener
	{
	public: 
		virtual bool keyPressed(Constants::Key key) { return false; }
	};
	
	/*
	* Input Manager
	* Class to manage input coming from Keyboard mapped from SDL2 events
	*/

	class CInputManager
	{
	public:
		static CInputManager& Instance()
		{
			static CInputManager _instance;
			return _instance;
		}
		
		void addKeyListener(CKeyboardListener *keyListener);
		void removeKeyListener(CKeyboardListener *keyListener);
		void Update();

	protected:
		CInputManager();
		CInputManager(const CInputManager&);
		CInputManager& operator=(const CInputManager&);
		~CInputManager();
		
	private:
		//Will hold all the keyboard listener and every object is responsible to attach to it
		std::list<CKeyboardListener*> _keyboardListeners;
		//Utility to convert from SDL_Keysym to Constants::Key
		Constants::Key _SDLKey2GameKey(const SDL_Keysym &key);
		//Internal method that will be called after SDL key input happens
		bool _KeyPressed(const SDL_Keysym &key);
	};
}

#endif