#include <map>
#include "core/AComponent.hpp"
#include "core/ComponentData.hpp"

namespace NG {

	std::map<unsigned int, AComponent*> Components;

	unsigned int AComponent::Count(0);
	AComponent::AComponent() : id(Count++) {}
	AComponent::~AComponent() {}

	unsigned int ComponentData::Count(0);
	ComponentData::ComponentData() : id(Count++) {}
	ComponentData::~ComponentData() {}

}
