#ifndef EVENT_HPP
#define EVENT_HPP

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
		class Event : public AEvent {

			public :

				Event(unsigned int type, unsigned int emitterID)
					: AEvent(type, emitterID)
				{
					EventData* d = dynamic_cast<EventData*>(&Data);
					assert(d != NULL);
					d = NULL;
				}

				~Event() {}

				T Data;
		};
}

#endif
