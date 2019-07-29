#ifndef ENTITY
#define ENTITY

#include <iostream>
#include "Graphics\FrameAnimationSet.h"

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

			std::string entityName;
			bool isActive;
			float x, y;
			float moveSpeed;
			float maxMoveSpeed;
			float scale;
			float frameTimer;
		
			Graphics::FrameAnimationSet *entityFAnimationSet;
			Graphics::FrameAnimation *currentFAnimation;
			Graphics::Frame *currentFrame;
	};
}

#endif