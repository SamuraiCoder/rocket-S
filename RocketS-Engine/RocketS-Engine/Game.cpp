#include "Game.h"

#include <iostream>
#include "FrameAnimationSet.h"
#include "TimeManager.h"

using Graphics::FrameAnimationSet;

Game::Game()
{
		background = GM->loadTexture("background1.png");

		//FrameAnimationSet *hero = new FrameAnimationSet("heroFrameSet");
		//hero->loadAnimationSet("heroFrameSet",true, 0);
}

Game::~Game()
{
	//todo: implement!
}

void Game::update()
{
		bool exitApp = false;
		
		SDL_Event sdl_event;

		while (!exitApp)
		{
			TM->Update();
			while (SDL_PollEvent(&sdl_event))
			{
				switch (sdl_event.key.keysym.scancode)
				{
					case SDL_SCANCODE_ESCAPE:
						exitApp = true;
						break;
				}
			}

			//TODO: Update all entities

			//TODO: draw all entities
			draw();
		}
}

void Game::draw()
{
	//paint background
	GM->renderTexture(background);

	for (list<Logic::Entity*>::iterator ent = m_GameEntities.begin(); ent != m_GameEntities.end(); ++ent){
		(*ent)->Draw();
	}
}
