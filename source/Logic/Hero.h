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
		Hero(const std::string &heroName, float positionX, float positionY, float scale, float speedMove, float maxSpeedMove, const std::string &frameAnimSetName);
		~Hero();
		void Update();
	private:
		void UpdateFrameAnimation();
		void UpdateMove();
	};
}

#endif