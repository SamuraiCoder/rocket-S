#include "InputManager.h"

using std::cout;
using std::endl;

namespace GameUtils
{
	CInputManager::CInputManager()
	{
		cout << "[CInputManager] CInputManager init" << endl;
	}
	CInputManager::~CInputManager()
	{
		if (!_keyboardListeners.empty())
		{
			auto it = _keyboardListeners.begin();
			for (; it != _keyboardListeners.end(); )
			{
				_keyboardListeners.remove(*it++);
			}
		}

		_keyboardListeners.clear();
	}

	void CInputManager::Update()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
			case SDL_KEYDOWN:
			{
				_KeyPressed(event.key.keysym);
				break;
			}
			case SDL_KEYUP:
			{
				_KeyReleased(event.key.keysym);
				break;
			}
			default:
				break;
			}
		} 
	}

	void CInputManager::addKeyListener(CKeyboardListener *keyListener)
	{
		_keyboardListeners.push_front(keyListener);
	}

	void CInputManager::removeKeyListener(CKeyboardListener *keyListener)
	{
		_keyboardListeners.remove(keyListener);
	}

	bool CInputManager::_KeyPressed(const SDL_Keysym &key)
	{
		if (!_keyboardListeners.empty())
		{
			std::list<CKeyboardListener*>::const_iterator it;
			it = _keyboardListeners.begin();
			for (; it != _keyboardListeners.end(); ++it)
			{
				if ((*it)->KeyPressed(_SDLKey2GameKey(key)))
					break;
			}
		}
		return false;
	}

	bool CInputManager::_KeyReleased(const SDL_Keysym &key)
	{
		if (!_keyboardListeners.empty())
		{
			std::list<CKeyboardListener*>::const_iterator it;
			it = _keyboardListeners.begin();
			for (; it != _keyboardListeners.end(); ++it)
			{
				if ((*it)->KeyReleased(_SDLKey2GameKey(key)))
					break;
			}
		}
		return false;
	}

	Constants::Key CInputManager::_SDLKey2GameKey(const SDL_Keysym &key)
	{
		Constants::Key tmpKey;

		switch (key.scancode)
		{
		case SDL_SCANCODE_ESCAPE:
			tmpKey = Constants::Key::KEY_ESCAPE;
			break;
		case SDL_SCANCODE_W:
			tmpKey = Constants::Key::KEY_W;
			break;
		case SDL_SCANCODE_A:
			tmpKey = Constants::Key::KEY_A;
			break;
		case SDL_SCANCODE_S:
			tmpKey = Constants::Key::KEY_S;
			break;
		case SDL_SCANCODE_D:
			tmpKey = Constants::Key::KEY_D;
			break;
		case SDL_SCANCODE_SPACE:
			tmpKey = Constants::Key::KEY_SPACE;
			break;
		case SDL_SCANCODE_K:
			tmpKey = Constants::Key::KEY_K;
			break;
		case SDL_SCANCODE_BACKSPACE:
			tmpKey = Constants::Key::KEY_BACKSPACE;
			break;
		default:
			tmpKey = Constants::Key::KEY_NULL;
			break;
		}

		return tmpKey;
	}

}
