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

		protected :

			int					State;
			std::mutex	Mutex;

		public :

			ComponentData();
			virtual ~ComponentData();

			int					GetState();
			void				SetState(int);

	};


	extern std::vector<AComponent*> Components;

	template<class T>
		class Component : public AComponent {

			public :

				class DataType {

					T						Data;

					public :

					DataType() {}
					~DataType() {}

					void SetData(T data) {
						this->Mutex.lock();
						Data = data;
						this->Mutex.unlock();
					}

					T GetData(void) {
						T data;
						this->Mutex.lock();
						data = Data;
						this->Mutex.unlock();
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

				T	operator[](unsigned int key) {
					typename std::map<unsigned int,DataType>::iterator it;
					it = Data.find(key);
					if (it != Data.end())
						return it->second.GetData();
					T ret;
					ret.SetState(-1);
					return ret;	
				}
		};
}

#endif
