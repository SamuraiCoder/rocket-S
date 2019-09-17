#include "HeroController.h"
#include "GameUtils\Globals.h"
#include "GameUtils\TimeManager.h"
#include "Logic\Entity.h"

namespace Logic{
	bool HeroController::AcceptMessage(Message *msg)
	{
		return msg->getType() == Constants::MessageType::D_PRESSED_MOVE_FORWARD ||
			msg->getType() == Constants::MessageType::D_RELEASED_MOVE_FORWARD ||
			msg->getType() == Constants::MessageType::A_PRESSED_MOVE_BACKWARDS ||
			msg->getType() == Constants::MessageType::A_RELEASED_MOVE_BACKWARDS ||
			msg->getType() == Constants::MessageType::K_PRESSED_SHOOTING ||
			msg->getType() == Constants::MessageType::K_RELEASED_SHOOTING;
	}

	void HeroController::ProcessMessage(Message *msg)
	{
		switch (msg->getType())
		{
			case Constants::MessageType::D_PRESSED_MOVE_FORWARD:
			{
				_moveSpeed = 25.0f;
				_isMoving = true;
				_direction = Constants::Entity::DIRECTION_FORWARD;
				break;
			}
			case Constants::MessageType::A_PRESSED_MOVE_BACKWARDS:
			{
				_moveSpeed = 25.0f;
				_isMoving = true;
				_direction = Constants::Entity::DIRECTION_BACKWARDS;
				break;
			}
			case Constants::MessageType::D_RELEASED_MOVE_FORWARD:
			{
				_isMoving = false;
				break;
			}
			case Constants::MessageType::A_RELEASED_MOVE_BACKWARDS:
			{
				_isMoving = false;
				break;
			}
			case Constants::MessageType::K_PRESSED_SHOOTING:
			{
				_isShooting = true;
				break;
			}
			case Constants::MessageType::K_RELEASED_SHOOTING:
			{
				_isShooting = false;
				break;
			}
		}
	}

	void HeroController::Update()
	{
		BaseComponent::Update();

		if (_moveSpeed > 0.0f)
		{
			float distanceMoved = _moveSpeed * (GameUtils::CTimeManager::Instance().DeltaTime()) * 10.0f;
			if (distanceMoved > 0)
			{
				if (!_isShooting && _direction == Constants::Entity::DIRECTION_FORWARD)
				{
					_entity->x += distanceMoved;
					_entity->flip = false;
				}

				if (!_isShooting && _direction == Constants::Entity::DIRECTION_BACKWARDS)
				{
					_entity->x -= distanceMoved;
					_entity->flip = true;
				}

				//Inertial movement when keys are not pressed
				if (!_isMoving)
				{
					_moveSpeed -= distanceMoved * 1.5f;
				}
			}
			_entity->isMoving = _isMoving; //Update the entity's status
		}
	}
}