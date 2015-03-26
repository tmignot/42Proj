#include "Entity.class.hpp"

unsigned int Entity::currentID(0);

Entity::Entity() : ID(Entity::currentID++){}
Entity::~Entity() {}
