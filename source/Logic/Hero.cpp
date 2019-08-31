#include "Hero.h"
#include "Graphics\FrameAnimationSet.h"
#include "GameUtils\TimeManager.h"

#include "Logic\HeroController.h"

using Graphics::FrameAnimationSet;


namespace Logic{
	Hero::Hero(const std::string &heroName, float positionX, float positionY, float entityScale, float speedMove, float maxSpeedMove, const std::string &frameAnimSetName)
	{
		//Create the animSet.
		FrameAnimationSet *heroAnimSet = new FrameAnimationSet(frameAnimSetName);
		heroAnimSet->loadAnimationSet(frameAnimSetName, false, 0);
		//and assing it to the entity (hero) one.
		entityFAnimationSet = heroAnimSet;
		//TODO: fix all the animations in an external source out of here.
		currentFAnimation = entityFAnimationSet->getFrameAnimationSet("idle");
		currentFrame = currentFAnimation->getFrame(0);

		//currentFAnimation = entityFAnimationSet->getFrameAnimationSet("run-forward-w-gun");
		//currentFrame = currentFAnimation->getFrame(0);

		//Create entity Hero
		entityName = heroName;
		x = positionX;
		y = positionY;
		moveSpeed = speedMove;
		maxMoveSpeed = maxSpeedMove;
		scale = entityScale;

		//Create components
		HeroController *hController = new HeroController("HeroController");
		hController->InitiateComponent(this);

		//Attach the component to the Entity
		Entity::AddComponent(hController);

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
			UpdateFrameAnimation();
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