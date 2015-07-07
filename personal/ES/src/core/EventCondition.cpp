#include "core/EventCondition.hpp"

namespace NG {

	EventCondition::EventCondition()
	{
		event = NULL;
		system = 0;
	}

	EventCondition::EventCondition(unsigned int s, std::vector<unsigned int> p)
	{
		event = NULL;
		system = s;
		param = p;
	}
	EventCondition::~EventCondition() {}

}
