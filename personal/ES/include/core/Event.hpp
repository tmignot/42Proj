#ifndef EVENT_HPP
#define EVENT_HPP

#include <cassert>
#include <ruby.h>
#include <vector>

#include "core/EventCondition.hpp"
#include "core/System.hpp"

namespace NG {

	class Event {

		private :

			static unsigned int	 Count;

			unsigned int											id;
			VALUE															Callback;
			std::vector<EventCondition*>			Conditions;

		public :

			void	Check();
			bool	Call(std::vector<int> states);

			Event(std::vector<EventCondition*> c, VALUE cb);
			~Event();

	};

	class ASystem;
	extern std::map<unsigned int,ASystem*> Systems;

}

#endif
