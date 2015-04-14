#ifndef  ENTITY_HPP
#define  ENTITY_HPP

#include <array>
#include <vector>

#include "core/ComponentMask.hpp"

namespace NG {

	class Entity {

		private :

			static unsigned int	count;

		public :

			unsigned int		ID;
			Entity*					Ptr;
			ComponentMask		Mask;

			Entity();
			~Entity();
	};

	extern std::vector<Entity*> Entities;

}
#endif    /* ENTITY_HPP */
