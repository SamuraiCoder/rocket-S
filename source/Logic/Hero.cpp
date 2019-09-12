#include "Hero.h"
#include "Graphics\FrameAnimationSet.h"
#include "GameUtils\TimeManager.h"

#include "Logic\HeroController.h"
#include "Logic\HeroAnimationController.h"

using Graphics::FrameAnimationSet;


namespace Logic{
	Hero::Hero(const std::string &heroName, float positionX, float positionY, float entityScale, float speedMove, float maxSpeedMove, const std::string &frameAnimSetName)
	{
		//Create the animSet.
		FrameAnimationSet *heroAnimSet = new FrameAnimationSet(frameAnimSetName);
		heroAnimSet->loadAnimationSet(frameAnimSetName, false, 0);
		//and assing it to the entity (hero) one.
		entityFAnimationSet = heroAnimSet;

		//Create entity Hero
		entityName = heroName;
		x = positionX;
		y = positionY;
		moveSpeed = speedMove;
		maxMoveSpeed = maxSpeedMove;
		scale = entityScale;
		isMoving = false;

		//Create component for controlling the movement
		HeroController *hController = new HeroController("HeroController");
		hController->InitiateComponent(this);
		//Attach the component to the Entity
		Entity::AddComponent(hController);

		//Create component for displaying animation
		HeroAnimationController *hAnimationController = new HeroAnimationController("HeroAnimationController");
		hAnimationController->InitiateComponent(this);
		//Attach the component to the Entity
		Entity::AddComponent(hAnimationController);

		//Init all the components 
		Entity::InitComponents();
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
			Entity::UpdateComponents();
			UpdateFrameAnimation(); //TODO weird naming. Think to change it. 
		}
	}
	
	void Hero::UpdateFrameAnimation()
	{
		if (currentFrame == nullptr || currentFAnimation == nullptr)
			return; 

		frameTimer += GameUtils::CTimeManager::Instance().DeltaTime();
		
		//Current frame duration it's over?
		if (frameTimer >= currentFrame->GetFrameDuration())
		{
			currentFrame = currentFAnimation->getNextFrame(currentFrame);
			frameTimer = 0;
		}
	}
}