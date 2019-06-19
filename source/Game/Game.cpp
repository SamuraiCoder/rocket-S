#include "Game.h"

#include <iostream>
#include "Logic\Hero.h"

using Logic::Hero;

Game::Game()
{
		background = Graphics::CGraphicsManager::Instance().loadTexture("background1.png");

		Hero *hero = new Hero("Marco_Rossi", 100.0f, 650.0f, 2.0f, 0.5, 1.0f, "marco_rossi.fas");
		m_GameEntities.push_back(hero);
}

Game::~Game()
{
	for (auto ent = m_GameEntities.begin(); ent != m_GameEntities.end(); ++ent)
		delete (*ent);

	m_GameEntities.clear();
}

void Game::update()
{
		bool exitApp = false;
		
		SDL_Event sdl_event;

		while (!exitApp)
		{
			GameUtils::CTimeManager::Instance().Update();
			while (SDL_PollEvent(&sdl_event))
			{
				switch (sdl_event.key.keysym.scancode)
				{
					case SDL_SCANCODE_ESCAPE:
						exitApp = true;
						break;
				}
			}

			updateEntities();
			drawEntities();
		}
}

void Game::drawEntities()
{
	//paint background
	Graphics::CGraphicsManager::Instance().renderTexture(background);

	for (auto ent = m_GameEntities.begin(); ent != m_GameEntities.end(); ++ent){
		(*ent)->Draw();
	}
}

void Game::updateEntities()
{
	for (auto ent = m_GameEntities.begin(); ent != m_GameEntities.end(); ++ent){
		(*ent)->Update();
	}
}
