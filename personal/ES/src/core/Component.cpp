#include "core/Component.hpp"

namespace NG {

	std::vector<AComponent*> Components;

	unsigned int AComponent::Count(0);

	AComponent::AComponent() : ID(Count++) {}
	AComponent::~AComponent() {}

	ComponentData::ComponentData() : State(0) {}
	ComponentData::~ComponentData() {}

}
