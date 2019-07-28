#ifndef STATICENTITY
#define STATICENTITY

/*
	StaticEntity class. It represents a sprite that doesn't move and doesn't make animations.
*/

#include "Entity.h"

namespace Logic{
	class StaticEntity : public Entity
	{
	public:
		StaticEntity(const std::string &staticEntityName, float positionX, float positionY, float scale, const std::string &frameAnimSetName);
		~StaticEntity() {};
		void Update();
	private:

	};
}

#endif