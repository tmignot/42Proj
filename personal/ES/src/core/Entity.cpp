#include "core/Entity.hpp"

namespace NG {
	unsigned int Entity::count(0);

	Entity::Entity()
		: ID(Entity::count++)
	{}

	Entity::~Entity() {}
}
