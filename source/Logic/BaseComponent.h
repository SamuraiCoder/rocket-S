#ifndef BASE_COMPONENT
#define BASE_COMPONENT

#include "MessageDispatcher.h"
#include <iostream>


namespace Logic
{
	class Entity;
}
/*
	BaseComponent:
	base class that fits a specific Component. It will be attach to an Entity
	and it will receive messages to act upon.
*/

namespace Logic {
	class BaseComponent: public MessageDispatcher
	{
		public:
			//Base constructor. 
			BaseComponent() : _entity(0){ }
			//Base destructor (does nothing)
			virtual ~BaseComponent() {}
			//It is called when entity is created in order to initiate all the components. 
			virtual bool InitiateComponent(Entity* entity);
			virtual void Update();
			Entity *GetLinkedEntity() const { return _entity; }
	protected:
		Entity *_entity;
	};
}

#endif