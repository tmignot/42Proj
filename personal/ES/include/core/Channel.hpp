#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <list>

namespace NG {

	template<class T>
		class Channel : private std::list<T*> {

			private :

				std::mutex	Mutex;

			public :

				Channel(void) : std::list() {};

				~Channel(void) {
					Mutex.lock();
					while (!empty()) {
						delete front();
						pop_front();
					}
					clear();
				}

				T*			Poll(void) {
					if (Mutex.try_lock()) {
						if (size > 0) {
							T* val = front();
							pop_front();
							return val;
						}
						Mutex.unlock();
					}
					return NULL;
				}

				void		Peep(T* elem) {
					Mutex.lock();
					push_back(elem);
					Mutex.unlock();
				}
		};
}
