#ifndef GAME
#define GAME

#include "GameUtils\Globals.h" 
#include "Logic\Entity.h"
#include "GameUtils\InputManager.h"
#include "Graphics\GraphicsManager.h"
#include "GameUtils\TimeManager.h"

class Game: 
	public GameUtils::CKeyboardListener 
{
	public:
		Game();
		~Game();

		void update();
		virtual bool keyPressed(Constants::Key key); //CInputManager
	private:
		void sortEntities(Constants::Entity type);
		void drawEntities();
		void updateEntities();

		//Keeps a list of entities across the game
		list<Logic::Entity*> m_GameEntities;
		bool _exitApp = false;
};

#endif