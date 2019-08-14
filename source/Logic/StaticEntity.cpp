#include "Logic\StaticEntity.h"
#include "Graphics\FrameAnimationSet.h"
#include "GameUtils\TimeManager.h"
#include "GameUtils\InputManager.h"

using Graphics::FrameAnimationSet;

namespace Logic{
	StaticEntity::StaticEntity(const std::string &staticEntityName, float positionX, float positionY, float entityScale, const std::string &frameAnimSetName)
	{
		//Create the animSet.
		FrameAnimationSet *staticAnimSet = new FrameAnimationSet(frameAnimSetName);
		staticAnimSet->loadAnimationSet(frameAnimSetName, false, 0);

		//and assing it to the entity
		entityFAnimationSet = staticAnimSet;
		currentFAnimation = entityFAnimationSet->getFrameAnimationSet("static");
		currentFrame = currentFAnimation->getFrame(0);

		//Create static entity 
		entityName = staticEntityName;
		x = positionX;
		y = positionY;
		scale = entityScale;
	}

	void StaticEntity::Update()
	{
		if (entityFAnimationSet->isLoaded)
			isActive = true;
		else
			isActive = false;

		if (isActive)
		{
			UpdateFrameAnimation();
		}
	}

	void StaticEntity::UpdateFrameAnimation()
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