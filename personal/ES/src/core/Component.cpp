#include "core/Component.hpp"

std::vector<NG::AComponent*> NG::Components;

unsigned int NG::AComponent::Count(0);

NG::AComponent::AComponent() : ID(Count++) {}
NG::AComponent::~AComponent() {}

NG::ComponentData::ComponentData(bool active) : Active(active) {}
NG::ComponentData::~ComponentData() {}
