#ifndef STATICENTITY
#define STATICENTITY

/*
	StaticEntity: 
	It represents an entity that doesn't move but can show animations.
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
		void UpdateFrameAnimation();
	};
}

#endif