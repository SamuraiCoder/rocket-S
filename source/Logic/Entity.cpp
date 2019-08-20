#include "Entity.h"

namespace Logic {

	Entity::~Entity()
	{
		delete entityFAnimationSet;
		RemoveAllComponents();
	}

	void Entity::InitComponents()
	{
		bool correct = true;

		for (auto it = _components.begin(); it != _components.end() && correct; ++it)
			correct = (*it)->InitiateComponent(this) && correct;

		if (correct)
		{
			cout << "[Entity] " << entityName << " all components initialised"  << endl;
		}
		else
		{
			cout << "[Entity] " << entityName << " some errors during components initialize" << endl;
		}
	}

	void Entity::AddComponent(BaseComponent * comp)
	{
		_components.push_back(comp);
	}

	void Entity::RemoveComponent(BaseComponent * comp)
	{
		_components.remove(comp);
	}

	void Entity::RemoveAllComponents()
	{
		BaseComponent* componentToDelete;
		while (!_components.empty())
		{
			componentToDelete = _components.back();
			_components.pop_back();
			delete componentToDelete;
		}
	}

	void Entity::UpdateComponents()
	{
		for (auto it = _components.begin(); it != _components.end(); ++it)
		{
			(*it)->Update();
		}
	}

	bool Entity::SendMessage(Message *msg, BaseComponent *comp)
	{
		// Para saber si alguien quiso el mensaje.
		bool anyReceiver = false;
		for (auto it = _components.begin(); it != _components.end(); ++it)
		{
			// Al emisor no se le envia el mensaje.
			if (comp != (*it))
				(*it)->AddMessageToQueue(msg) || anyReceiver;
		}
		
		return anyReceiver;
	}
	
	void Entity::Update()
	{
	}

	void Entity::Draw()
	{
		if (currentFrame != nullptr && isActive){
			currentFrame->Draw(entityFAnimationSet->getSpriteSheet(), x, y, scale);
		}
	}
}

