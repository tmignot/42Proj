#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <cassert>
#include <mutex>
#include <bitset>
#include <vector>
#include <map>
#include <algorithm>

#ifndef N_COMPONENT
#define N_COMPONENT 0
#endif

namespace NG {

	typedef std::bitset<N_COMPONENT> ComponentMask;

	class AComponent {

		public :

			unsigned int							ID;

		protected :

			static unsigned int				Count;

			AComponent();
			virtual ~AComponent();
	};

	class ComponentData {

		public :

			bool				Active;

		protected :

			ComponentData(bool);
			virtual ~ComponentData();
	};


	extern std::vector<AComponent*> Components;

	template<class T>
		class Component : public AComponent {

			public :

				class DataType {

					T						Data;
					std::mutex	Mutex;

					public :

					DataType() {}
					~DataType() {}

					void Set(T data) {
						Mutex.lock();
						Data = data;
						Mutex.unlock();
					}

					T Get(void) {
						T data;
						Mutex.lock();
						data = Data;
						Mutex.unlock();
						return data;
					}
				};

				std::map<unsigned int,DataType>	Data;

				Component()	
					: AComponent()
				{
					T t;
					ComponentData* d = dynamic_cast<ComponentData*>(&t);
					assert(d != NULL);
					d = NULL;

					Components.push_back(this);
				}

				~Component() { 
					Data.clear();
					Components.erase(std::find(Components, this));
				}

				void	Set(unsigned int key, T data) {
					Data[key].Set(data);
				}
		};
}

#endif
