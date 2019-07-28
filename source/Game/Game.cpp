#include "Game.h"

#include <iostream>

using Logic::Hero;
using Logic::StaticEntity;


struct EntityYDepthComparator
{
	bool operator ()(const Logic::Entity* const& e1, const Logic::Entity* const &e2)
	{
		if (e1->y < e2->y)
			return true;
		else
		    return false;
	}
};


Game::Game()
{
	//Create background
	StaticEntity *wallBackground = new StaticEntity("wallBackground", 0.0f, 0.0f, 1, "background1.fas");
	m_GameEntities.push_back(wallBackground);

	//Create the Hero
	Hero *hero = new Hero("Marco_Rossi", 100.0f, 550.0f, 3.0f, 0.5, 1.0f, "marco_rossi.fas");
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
			m_GameEntities.sort(EntityYDepthComparator());
			updateEntities();
			drawEntities();
		}
}
void Game::drawEntities()
{
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