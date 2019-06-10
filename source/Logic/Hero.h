#ifndef HERO
#define HERO

/*
	Hero class. 
*/

#include "Entity.h"

namespace Logic{
	class Hero : public Entity
	{
	public:
		Hero(const std::string &heroName, Graphics::FrameAnimationSet *frameAnimSet);
		~Hero();
		void Update();
	private:
		void UpdateFrameAnimation();
		void UpdateMove();
	};
}

#endif