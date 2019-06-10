#include "Entity.h"

namespace Logic {
	//const std::string &name, float positionX, float positionY, float speedMove, float maxSpeedMove, Graphics::FrameAnimationSet *frameAnimationSet = nullptr
	Entity::Entity(const std::string &name, float positionX, float positionY, float speedMove, float maxSpeedMove, Graphics::FrameAnimationSet *frameAnimationSet) :
		entityName(name),
		positionX(positionX),
		positionY(positionY),
		speedMove(speedMove),
		maxSpeedMove(maxSpeedMove)
	{
		entityFAnimationSet = frameAnimationSet;
	}

	Entity::~Entity()
	{
		//todo: implement!
	}
	void Entity::Update(){}

	void Entity::Draw()
	{
		if (currentFrame != nullptr && isActive){
			currentFrame->Draw(entityFAnimationSet->getSpriteSheet(), positionX, positionY);
		}
	}

}