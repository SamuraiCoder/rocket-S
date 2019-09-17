#include "HeroAnimationController.h"
#include "GameUtils\Globals.h"
#include "Logic\Entity.h"

namespace Logic{
	bool HeroAnimationController::AcceptMessage(Message *msg)
	{
		return msg->getType() == Constants::MessageType::D_PRESSED_MOVE_FORWARD		|| 
			   msg->getType() == Constants::MessageType::D_RELEASED_MOVE_FORWARD	||
			   msg->getType() == Constants::MessageType::A_PRESSED_MOVE_BACKWARDS	||
			   msg->getType() == Constants::MessageType::A_RELEASED_MOVE_BACKWARDS	||
			   msg->getType() == Constants::MessageType::K_PRESSED_SHOOTING			||
			   msg->getType() == Constants::MessageType::K_RELEASED_SHOOTING;
	}

	void HeroAnimationController::ProcessMessage(Message *msg)
	{
		switch (msg->getType())
		{
			case Constants::MessageType::D_PRESSED_MOVE_FORWARD:
			{
				_newHeroState = Constants::HeroState::HERO_WALKING;
				break;
			}
			case Constants::MessageType::A_PRESSED_MOVE_BACKWARDS:
			{
				_newHeroState = Constants::HeroState::HERO_WALKING;
				break;
			}
			case Constants::MessageType::D_RELEASED_MOVE_FORWARD:
			{
				_newHeroState = Constants::HeroState::HERO_IDLE;
				break;
			}
			case Constants::MessageType::A_RELEASED_MOVE_BACKWARDS:
			{
				_newHeroState = Constants::HeroState::HERO_IDLE;
				break;
			}
			case Constants::MessageType::K_PRESSED_SHOOTING:
			{
				_newHeroState = Constants::HeroState::HERO_SHOOTING;
				break;
			}
			case Constants::MessageType::K_RELEASED_SHOOTING:
			{
				_newHeroState = Constants::HeroState::HERO_IDLE;
				break;
			}
		}
	}

	void HeroAnimationController::Update()
	{
		BaseComponent::Update();

		//From IDLE to SHOOT
		if (_oldHeroState == Constants::HeroState::HERO_IDLE && _newHeroState == Constants::HeroState::HERO_SHOOTING)
		{
			_UpdateAnimation(Constants::HeroState::HERO_SHOOTING);
		}
		
		//From IDLE/WALK to IDLE
		if (_oldHeroState == Constants::HeroState::HERO_SHOOTING && _newHeroState == Constants::HeroState::HERO_IDLE)
		{
			_UpdateAnimation(Constants::HeroState::HERO_IDLE);
		}

		//From IDLE to WALK
		if (_oldHeroState == Constants::HeroState::HERO_IDLE && _newHeroState == Constants::HeroState::HERO_WALKING)
		{
			_UpdateAnimation(Constants::HeroState::HERO_WALKING);
		}

		//From WALK to IDLE
		if (_oldHeroState == Constants::HeroState::HERO_WALKING && !_entity->isMoving)
		{
			_UpdateAnimation(Constants::HeroState::HERO_IDLE);
		}
	}

	void HeroAnimationController::_UpdateAnimation(Constants::HeroState newState)
	{
		switch (newState)
		{
			case Constants::HeroState::HERO_IDLE:
			{
				_entity->currentFAnimation = _entity->entityFAnimationSet->getFrameAnimationSet(Constants::ANIM_HERO_IDLE);
				_entity->currentFrame = _entity->currentFAnimation->getFrame(0);
				break;
			}
			case Constants::HeroState::HERO_IDLE_DRINKING:
			{
				_entity->currentFAnimation = _entity->entityFAnimationSet->getFrameAnimationSet(Constants::ANIM_HERO_IDLE_DRINKING);
				_entity->currentFrame = _entity->currentFAnimation->getFrame(0);
				break;
			}
			case Constants::HeroState::HERO_RELOADING:
			{
				_entity->currentFAnimation = _entity->entityFAnimationSet->getFrameAnimationSet(Constants::ANIM_HERO_RELOADING);
				_entity->currentFrame = _entity->currentFAnimation->getFrame(0);
				break;
			}
			case Constants::HeroState::HERO_SHOOTING:
			{
				_entity->currentFAnimation = _entity->entityFAnimationSet->getFrameAnimationSet(Constants::ANIM_HERO_SHOOTING);
				_entity->currentFrame = _entity->currentFAnimation->getFrame(0);
				break;
			}
			case Constants::HeroState::HERO_WALKING:
			{
				_entity->currentFAnimation = _entity->entityFAnimationSet->getFrameAnimationSet(Constants::ANIM_HERO_WALKING);
				_entity->currentFrame = _entity->currentFAnimation->getFrame(0);
				break;
			}
		}
		//Update the Hero's state
		_oldHeroState = _newHeroState;
	}
}