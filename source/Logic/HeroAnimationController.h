#ifndef HERO_ANIMATION_CONTROLLER
#define HERO_ANIMATION_CONTROLLER

/*
	HeroAnimationController: 
	Component that manages what animation to show according to the movement (keyboard)
*/

#include "BaseComponent.h"

namespace Logic{
	class HeroAnimationController : public BaseComponent
	{
	public:
		//Default constructor
		HeroAnimationController() : BaseComponent() {}

		//Constructor with componentName
		HeroAnimationController(std::string componentName) : BaseComponent(), 
															_newHeroState(Constants::HeroState::HERO_IDLE),
															_oldHeroState(Constants::HeroState::HERO_WALKING)
		{
			_componentName = componentName;
		}

		virtual bool AcceptMessage(Message *message);
		virtual void ProcessMessage(Message *message);
		virtual void Update();
	private:
		void _UpdateAnimation(Constants::HeroState);
		Constants::HeroState _newHeroState;
		Constants::HeroState _oldHeroState;
	};
}

#endif