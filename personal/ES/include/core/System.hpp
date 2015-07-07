#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "core/Component.hpp"
#include "core/Channel.hpp"
#include "core/Event.hpp"
#include "core/EventCondition.hpp"
#include "core/Timer.hpp"
#include <thread>

namespace NG {

	class ASystem {

		private :

			bool					Run;
			bool					Paused;
			unsigned int	Fps;
			Timer					TimeController;

			std::thread							*Thread;
			std::mutex							Mutex;
			std::mutex							LockMutex;
			std::condition_variable	Condition;

			void	Loop(void);
			void	Sleep();

		protected :

			static unsigned int	Count;

			std::vector<unsigned int>														Watched;
			std::map<unsigned int,std::vector<EventCondition*> >	Listeners;

			ASystem(unsigned int fps);
			virtual ~ASystem();

			virtual void OnInit() = 0;
			virtual void OnUpdate() = 0;
			virtual void OnPause() = 0;
			virtual void OnResume() = 0;
			virtual void OnStop() = 0;

			void StateChanged(unsigned int);


		public :

			unsigned int		id;

			void Pause();
			void Resume();

			void Watch(unsigned int component);
			void Ignore(unsigned int component);

			void AddListener(EventCondition* condition);
			void RemoveListener(EventCondition* condition);

			virtual int	 GetState(std::vector<unsigned int>) = 0;
	};

	/*
		class System : public ASystem {

			public :

				System(unsigned int fps) : ASystem(fps) {}
				virtual ~System() {}

				int GetState(std::vector<unsigned int> components) {
					if (components.size() == 2) {
						if (collides[components[1]].contains(components[2])
								|| collides[components[2]].contains(components[1]))
							return 1;
					}
					return 0;
				}

				void onUpdate() {
					foreach watched |c1| {
						foreach watched |c2| {
							if (c1 != c2) {
								if (Colliders[c1].collides(Colliders[c2])) {
									collides[c1].add(c2);
									collides[c2].add(c1);
									StateChanged(c1);
									StateChanged(c2);
								}
								else {
									if (collides[c1].contains(c2)) {
										collides[c1].remove(c2);
										StateChanged(c1);
									}
									if (collides[c2].contains(c1)) {
										collides[c2].remove(c1);
										StateChanged(c2);
									}
								}
							}
						}
					}
				}
		};
		*/
}

#endif
