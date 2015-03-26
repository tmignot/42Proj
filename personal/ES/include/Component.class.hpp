#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <map>

struct Component_Data {
	bool	active;
}

template<typename T>
class Component : private std::map<unsigned int, T> {
	public :
		void	addEntity(unsigned int entity) {
			(*this)[entity] = new T();
		}

		void	removeEntity(unsigned int entity) {
			delete (*this)[entity];
			(*this)[entity] = NULL;
		}
};

#endif
