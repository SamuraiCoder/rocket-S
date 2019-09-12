#ifndef ENTITY
#define ENTITY

#include <iostream>
#include "Graphics\FrameAnimationSet.h"
#include "BaseComponent.h"

/*
	Entity:
	Acts as an interface for entities (hero, enemies, props, bullets...) in a game scene.
*/

namespace Logic {
	class Entity
	{
		public:
			virtual ~Entity();
			virtual void Update();
			virtual void Draw();
			void InitComponents();
			void UpdateComponents();
			void AddComponent(BaseComponent* component);
			void RemoveComponent(BaseComponent* component);
			void RemoveAllComponents();
			bool SendMessage(Message *msg, BaseComponent* emitter = 0);

			std::string entityName;
			bool isActive;
			float x, y;
			float moveSpeed;
			float maxMoveSpeed;
			float scale;
			bool flip;
			float frameTimer;
			bool isMoving;
		
			Graphics::FrameAnimationSet *entityFAnimationSet;
			Graphics::FrameAnimation *currentFAnimation;
			Graphics::Frame *currentFrame;

		protected:
			//This will hold a list of components 
			std::list<BaseComponent*> _components;
	};
}

#endif