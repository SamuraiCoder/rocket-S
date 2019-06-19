#include "Entity.h"

namespace Logic {
	Entity::~Entity()
	{
		delete entityFAnimationSet;
	}
	void Entity::Update()
	{ 
	}

	void Entity::Draw()
	{
		if (currentFrame != nullptr && isActive){
			currentFrame->Draw(entityFAnimationSet->getSpriteSheet(), entityPosX, entityPosY, entityScale);
		}
	}

}