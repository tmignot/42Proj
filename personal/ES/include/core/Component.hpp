#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <cassert>
#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <algorithm>

#include "core/Entity.hpp"
#include "core/SafeContainer.hpp"
#include "core/AComponent.hpp"
#include "core/ComponentData.hpp"

#define STATE_NOT_FOUND -1

namespace NG {

#ifndef SWIG
	extern std::map<unsigned int, AComponent*> components;
#endif

	template<class T>
		class Component : public AComponent {

			private :

				SafeMap<unsigned int,T*>	datas;

			public :

				Component()	
					: AComponent()
				{
					components[this->id] = this;
				}

				~Component() { 
					datas.Clear();
					components[this->id] = NULL;
				}

				T* get_data(unsigned int key) {
					if (datas.Find(key))
						return datas.GetData(key);
					return NULL;
				}

				unsigned int	create(void) {
					T* new_data = new T();
					datas.SetData(new_data->id, new_data);
					return new_data->id;
				}

				void	set_data(unsigned int key, T* data) {
					if (datas.Find(key))
						datas.SetData(key, data);
				}
		};
}
#endif
