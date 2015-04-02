#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <mutex>
#include <bitset>
#include <map>

#ifndef N_COMPONENT
#define N_COMPONENT 0
#endif

namespace NG {

	typedef std::bitset<N_COMPONENT> ComponentMask;

	class AComponent {

		public :

			unsigned int							ID;

		protected :

			static unsigned int				Count(0);

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
				
				class DataType : private std::pair<std::mutex,T> {
					
					public :

						DataType() : std::pair() {}
						~DataType() {}

						Set(T data) {
							first.lock();
							second = data;
							first.unlock();
						}

						T Get(void) {
							T data;
							first.lock();
							data = second;
							first.unlock();
							return data;
						}
				};

				std::map<unsigned int,DataType<T> >	Data;

				Component()	
					: AComponent(), ID(Count++)
				{
					T t;
					ComponentData* d = dynamic_cast<ComponentData*>(&t);
					assert(d != NULL);
					d = NULL;

					Components.push_back(this);
				}

				~Component() { 
					Data.clear();
				}

				void	Set(unsigned int key, T data) {
					Data[key].Set(data);
				}
		};

	extern void	DeleteComponents(void);
}

#endif
