#ifndef HERO
#define HERO

/*
	Hero:
	It represents a hero. It will receive moving commands and show animations. A
*/

#include "Entity.h"

namespace Logic{
	class Hero : public Entity
	{
	public:
		Hero(const std::string &heroName, float positionX, float positionY, float scale, float speedMove, float maxSpeedMove, const std::string &frameAnimSetName);
		~Hero();
		void Update();
		void InitComponents();

	private:
		void UpdateFrameAnimation();
	};
}

#endif