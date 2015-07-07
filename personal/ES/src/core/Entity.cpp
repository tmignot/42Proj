#include "core/Entity.hpp"
#include <iostream>
#include <ruby.h>

namespace NG {
	unsigned int Entity::Count(0);
	std::map<unsigned int, Entity*> Entities;

	Entity::Entity()
		: std::map<unsigned int, unsigned long>()
	{
		unsigned int id = Count++;
		(*this)[rb_intern("id")] = id;
		std::cout << rb_intern("id") << std::endl;
		Entities[id] = this;
	}

	Entity::~Entity() {}

	void Entity::Set(char* symbol, unsigned long value) {
		(*this)[rb_intern(symbol)] = value;
	}
}
