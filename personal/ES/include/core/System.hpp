#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "core/Component.hpp"
#include "core/Channel.hpp"
#include "core/Event.hpp"
#include <thread>

namespace NG {

	class ASystem {

		public :

			unsigned int		ID;

		protected :

			static unsigned int	Count;

			ComponentMask				RequiredComponents;
			std::vector<unsigned int>	Entities;
			std::thread					Thread;

			ASystem(ComponentMask);
			virtual ~ASystem();

	};

	template<class T, class U>
		class System : public ASystem {

			public :

				typedef Channel<T>	Channel;
				typedef Event<U>	Event;

				Channel		Input;
				
				System() {}
				virtual ~System() {}
		};
}

#endif
