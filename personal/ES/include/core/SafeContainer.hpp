#ifndef SAFE_CONTAINER_HPP
#define SAFE_CONTAINER_HPP

#include <mutex>

namespace NG {

	template<class K, class T>
		class SafeMap {

			private :

				std::mutex			Mutex;
				std::map<K,T>		Data;

			public :

				SafeMap() {}
				~SafeMap() {}

				void SetData(K key, T data) {
					Mutex.lock();
					Data[key] = data;
					Mutex.unlock();
				}

				T GetData(K key) {
					T data;
					Mutex.lock();
					data = Data[key];
					Mutex.unlock();
					return data;
				}

				bool Find(unsigned int key) {
					bool ret;
					typename std::map<K, T>::iterator it;
					Mutex.lock();
					ret = Data.find(key) != Data.end();
					Mutex.lock();
					return ret;
				}

				void Clear() {
					Mutex.lock();
					Data.clear();
					Mutex.unlock();
				}
		};
}

#endif
