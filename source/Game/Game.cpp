#include "Game.h"

#include <iostream>
#include "Logic\Hero.h"
#include "Logic\StaticEntity.h"

using Logic::Hero;
using Logic::StaticEntity;

Game::Game()
{
	//Attach this class to the InputManager through a keyboard listener
	GameUtils::CInputManager::Instance().addKeyListener(this);

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
	while (!_exitApp)
	{
		GameUtils::CTimeManager::Instance().Update();
		GameUtils::CInputManager::Instance().Update();
			
		sortEntities(Constants::Entity::POSITION_Y);
		drawEntities();
		updateEntities();
	}
}

void Game::sortEntities(Constants::Entity type)
{
	auto sortCompare = [type](const Logic::Entity* const& e1, const Logic::Entity* const &e2)
	{
		switch (type)
		{
		case Constants::Entity::POSITION_X:
		{
			if (e1->x < e2->x)
				return true;
			else
				return false;
			break;
		}
		case Constants::Entity::POSITION_Y:
		{
			if (e1->y < e2->y)
				return true;
			else
				return false;
			break;
		}
		default:
			return false;
			break;
		}
	};
	m_GameEntities.sort(sortCompare);
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

bool Game::keyPressed(Constants::Key key)
{
	switch (key)
	{
	case Constants::Key::KEY_ESCAPE:
		_exitApp = true;
		break;
	}
	
	return false;
}
