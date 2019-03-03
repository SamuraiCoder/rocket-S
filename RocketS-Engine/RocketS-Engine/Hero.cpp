#include "Hero.h"

namespace Logic{
	Hero::Hero(const std::string &heroName, Graphics::FrameAnimationSet *frameAnimSet)
	{
		Entity(heroName, 100.0f, 100.0f, 0.2, 0.5, frameAnimSet);
	}

	Hero::~Hero()
	{

	}

	void Hero::Update()
	{

		UpdateFrameAnimation();
		UpdateMove();
	}
	
	void Hero::UpdateFrameAnimation()
	{
		if (currentFrame == nullptr || currentFAnimation == nullptr)
			return; 

		fTimer += TM->DeltaTime();
		
		//Current frame duration it's over?
		if (fTimer >= currentFrame->GetFrameDuration())
		{
			currentFrame = currentFAnimation->getNextFrame(currentFrame);
			fTimer = 0;
		}
	}
	
	void Hero::UpdateMove()
	{

	}
}