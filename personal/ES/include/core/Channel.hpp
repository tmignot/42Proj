#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <list>
#include <mutex>

namespace NG {

	template<class T>
		class Channel : private std::list<T*> {

			private :

				std::mutex	Mutex;

			public :

				Channel(void) : std::list<T*>() {};

				~Channel(void) {
					Mutex.lock();
					while (!this->empty()) {
						delete this->front();
						this->pop_front();
					}
					this->clear();
				}

				T*	Poll(void) {
					if (Mutex.try_lock()) {
						if (this->size > 0) {
							T* val = this->front();
							this->pop_front();
							return val;
						}
						Mutex.unlock();
					}
					return NULL;
				}

				void	Peep(T* elem) {
					Mutex.lock();
					this->push_back(elem);
					Mutex.unlock();
				}
		};
}

#endif
