#ifndef ENTITY
#define ENTITY

#include <iostream>
#include "Graphics\FrameAnimationSet.h"

/*
	Entity class. It represents an entity (hero, enemies, props, bullets...) in a game scene.
*/

namespace Logic {
	class Entity
	{
		public:
			virtual ~Entity();
			virtual void Update();
			virtual void Draw();
	
		protected:
			std::string entityName;
			bool isActive;
			float entityPosX, entityPosY;
			float entitySpeedMove;
			float entityMaxSpeedMove;
			float entityScale;
			float entityFTimer;
		
			Graphics::FrameAnimationSet *entityFAnimationSet;
			Graphics::FrameAnimation *currentFAnimation;
			Graphics::Frame *currentFrame;
	};
}

#endif