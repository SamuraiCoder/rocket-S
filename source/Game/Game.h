#ifndef GAME
#define GAME

#include <SDL.h>
#include <SDL_image.h>
#include "Logic\Entity.h"
#include "Logic\Hero.h"
#include "Logic\StaticEntity.h"

using Logic::Hero;


class Game{
	public:
		Game();
		~Game();

		void update();
	private:
		void drawEntities();
		void updateEntities();

		//Keeps a list of entities across the game
		list<Logic::Entity*> m_GameEntities;
};

#endif