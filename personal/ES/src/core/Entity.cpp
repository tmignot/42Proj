#include "core/Entity.hpp"

namespace NG {
	unsigned int Entity::count(0);
	std::vector<Entity*> Entities;

	Entity::Entity()
		: ID(Entity::count++)
	{
		Entities.push_back(this);
		Ptr = this;
	}

	Entity::~Entity() {}

}
