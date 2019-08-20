#include "BaseComponent.h"

namespace Logic {
	bool BaseComponent::InitiateComponent(Entity *entity)
	{
		_entity = entity;

		if (_entity != nullptr)
			return true;
		else
			return false;
	} 

	void BaseComponent::Update()
	{
		ProcessAllMessages();
	} 
}

