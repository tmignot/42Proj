#ifndef EVENT_CONDITION_HPP
#define EVENT_CONDITION_HPP

#include <iostream>
#include <vector>
#include <map>

namespace NG {

	class Event;
	class ASystem;

	class EventCondition {

		public :
			
			Event*						event;
			unsigned int			system;
			std::vector<unsigned int>	param;

			EventCondition();
			EventCondition(unsigned int s, std::vector<unsigned int> p);
			~EventCondition();
	};

	extern std::map<unsigned int, ASystem*> Systems;
}

#endif
