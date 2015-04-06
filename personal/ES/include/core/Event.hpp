#ifndef EVENT_HPP
#define EVENT_HPP

#include <cassert>
#ifndef NULL
#define NULL 0
#endif

namespace NG {

	class AEvent {

		public :

			unsigned int	Type;
			unsigned int	EmitterID;

		protected :

			AEvent(unsigned int, unsigned int);
			virtual ~AEvent();
	};

	class EventData {

		protected :

			EventData();
			virtual ~EventData();
	};

	template<class T>
		class BaseEvent : public AEvent {

			public :

				BaseEvent(unsigned int type, unsigned int emitterID)
					: AEvent(type, emitterID)
				{
					EventData* d = dynamic_cast<EventData*>(&Data);
					assert(d != NULL);
					d = NULL;
				}

				~BaseEvent() {}

				T Data;
		};
}

#endif
