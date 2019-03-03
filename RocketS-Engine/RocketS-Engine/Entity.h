#ifndef ENTITY
#define ENTITY

#include <iostream>
#include "FrameAnimationSet.h"

/*
	Entity class. It represents an entity (hero, enemies, props, bullets...) in a game scene.
*/

namespace Logic {
	class Entity
	{
		public:
			Entity(){};
			Entity(const std::string &name, float positionX, float positionY, float speedMove, float maxSpeedMove, Graphics::FrameAnimationSet *frameAnimationSet = nullptr);
			virtual ~Entity();
			virtual void Update();
			virtual void Draw();
	
		protected:
			std::string entityName;
			bool isActive;
			float positionX, positionY;
			float speedMove;
			float maxSpeedMove;
			float fTimer; //duration of each frame
		
			Graphics::FrameAnimationSet *entityFAnimationSet;
			Graphics::FrameAnimation *currentFAnimation;
			Graphics::Frame *currentFrame;
	};
}

#endif