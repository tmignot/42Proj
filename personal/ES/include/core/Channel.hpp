#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <list>
#include <mutex>
#include <condition_variable>

namespace NG {

	template<class T>
		class BaseChannel : private std::list<T*> {

			private :

				std::mutex	Mutex;

			public :

				std::mutex							InputMutex;
				std::condition_variable	Condition;

				BaseChannel(void) : std::list<T*>() {};

				~BaseChannel(void) {
					Mutex.lock();
					while (!this->empty()) {
						delete this->front();
						this->pop_front();
					}
					this->clear();
				}

				T*	Poll(void) {
					T* val = NULL;

					Mutex.lock();
					if (this->size > 0) {
						val = this->front();
						this->pop_front();
					}
					Mutex.unlock();

					return val;
				}

				void	Peep(T* elem) {
					Mutex.lock();
					this->push_back(elem);
					Mutex.unlock();

					std::unique_lock<std::mutex>	lock(InputMutex);
					Condition.notify_one();
				}
		};
}

#endif
