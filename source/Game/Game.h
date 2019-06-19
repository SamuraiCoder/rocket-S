#ifndef GAME
#define GAME

#include <SDL.h>
#include <SDL_image.h>
#include "Logic\Entity.h"

#include "Logic\Hero.h"

using Logic::Hero;


class Game{
	public:
		Game();
		~Game();

		void update();

		//Todo: remove maybe?
		SDL_Texture* background;
	private:
		void drawEntities();
		void updateEntities();

		//Keeps a list of entities across the game
		list<Logic::Entity*> m_GameEntities;
};

#endif