#ifndef GLOBALS
#define GLOBALS

#include <SDL.h>
#include <iostream>

namespace Constants
{
	enum class Entity
	{
		DIRECTION_FORWARD,
		DIRECTION_BACKWARDS,
		POSITION_X,
		POSITION_Y
	};

	/*
	* It contains all the keyCodes coming from SDL and its association into this game.
	*/
	enum class Key
	{
		KEY_NULL					= 0,
		KEY_ESCAPE					= SDL_SCANCODE_ESCAPE,
		KEY_W						= SDL_SCANCODE_W,
		KEY_A						= SDL_SCANCODE_A,
		KEY_S						= SDL_SCANCODE_S,
		KEY_D						= SDL_SCANCODE_D,
		KEY_SPACE					= SDL_SCANCODE_SPACE,
		KEY_BACKSPACE				= SDL_SCANCODE_BACKSPACE
	};

	/*
	* It contains all the message's type available for sending. 
	*/
	enum class MessageType
	{
		D_PRESSED_MOVE_FORWARD,
		D_RELEASED_MOVE_FORWARD,
		A_PRESSED_MOVE_BACKWARDS,
		A_RELEASED_MOVE_BACKWARDS,
		ENTITY_CLICKED
	};

	/*
	* It contains a Hero status to see what animation should trigger: 
	  idle, walking with gun, drinking, shooting,..., etc
	*/
	enum class HeroState
	{
		HERO_IDLE,
		HERO_IDLE_DRINKING,
		HERO_WALKING,
		HERO_RELOADING,
		HERO_SHOOTING
	};

	/*
	* It contains animation's definition.
	*/
	const std::string ANIM_HERO_IDLE			= "idle";
	const std::string ANIM_HERO_IDLE_DRINKING	= "idle-drinking";
	const std::string ANIM_HERO_WALKING			= "run-forward-w-gun";
	const std::string ANIM_HERO_RELOADING		= "reloading";
	const std::string ANIM_HERO_SHOOTING		= "shooting";
}

#endif
