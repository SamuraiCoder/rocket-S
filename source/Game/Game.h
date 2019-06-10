#ifndef GAME
#define GAME

#include <SDL.h>
#include <SDL_image.h>
#include "Logic\Entity.h"

class Game{
	public:
		Game();
		~Game();

		void update();
		void draw();

		//Todo: remove maybe?
		SDL_Texture* background;

		//Keeps a list of entities across the game
		list<Logic::Entity*> m_GameEntities;
};

#endif