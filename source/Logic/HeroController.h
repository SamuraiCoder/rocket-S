#ifndef HERO_CONTROLLER
#define HERO_CONTROLLER

/*
	HeroController: 
	Component that manages input and moves the hero 
*/

#include "BaseComponent.h"

namespace Logic{
	class HeroController : public BaseComponent
	{
	public:
		//Default constructor
		HeroController() : BaseComponent() {}

		//Constructor with componentName
		HeroController(std::string componentName) : BaseComponent(),_isMoving(false), _moveSpeed(0.0f), _maxMoveSpeed(20.0f)
		{
			_componentName = componentName;
		}

		virtual bool AcceptMessage(Message *message);
		virtual void ProcessMessage(Message *message);
		virtual void Update();
	private:
		Constants::Entity _direction;
		bool _isMoving;	
		float _moveSpeed;
		float _maxMoveSpeed;
	};
}

#endif