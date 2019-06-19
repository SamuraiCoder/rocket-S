#include "Hero.h"

namespace Logic{
	Hero::Hero(const std::string &heroName, float positionX, float positionY, float scale, float speedMove, float maxSpeedMove, const std::string &frameAnimSetName)
	{
		//Create the animSet.
		FrameAnimationSet *heroAnimSet = new FrameAnimationSet(frameAnimSetName);
		//TODO: rework the background sprite.
		heroAnimSet->loadAnimationSet(frameAnimSetName, true, 1);
		//and assing it to the entity (hero) one.
		entityFAnimationSet = heroAnimSet;
		//TODO: fix all the animations in an external source out of here.
		currentFAnimation = entityFAnimationSet->getFrameAnimationSet("idle");
		currentFrame = currentFAnimation->getFrame(0);

		//Create entity Hero
		entityName = heroName;
		entityPosX = positionX;
		entityPosY = positionY;
		entitySpeedMove = speedMove;
		entityMaxSpeedMove = maxSpeedMove;
		entityScale = scale;
	}

	Hero::~Hero()
	{
		
	}

	void Hero::Update()
	{
		if (entityFAnimationSet->isLoaded)
			isActive = true;

		if (isActive)
		{
			UpdateFrameAnimation();
			UpdateMove();
		}
	}
	
	void Hero::UpdateFrameAnimation()
	{
		if (currentFrame == nullptr || currentFAnimation == nullptr)
			return; 

		entityFTimer += GameUtils::CTimeManager::Instance().DeltaTime();
		
		//Current frame duration it's over?
		if (entityFTimer >= currentFrame->GetFrameDuration())
		{
			currentFrame = currentFAnimation->getNextFrame(currentFrame);
			entityFTimer = 0;
		}
	}
	
	void Hero::UpdateMove()
	{

	}
}